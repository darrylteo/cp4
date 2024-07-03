#include <bits/stdc++.h>

using namespace std;

struct stampSet {
    int maxCov, numStamps;
    vector<int> stamps; // reversed so largest stamp is in front
};

// put better set in front
bool operator<(const stampSet &a, const stampSet &b) {
    if (a.maxCov != b.maxCov) return a.maxCov > b.maxCov;
    if (a.numStamps != b.numStamps) return a.numStamps < b.numStamps;
    for (int i = 0; i < a.numStamps; i++) {
        if (a.stamps[i] != b.stamps[i]) return a.stamps[i] < b.stamps[i]; // smaller largest stamp
    }
    return false; // equal
}

int S, N, V, cases, coinValue[105], found;
int memo[105][1005][15];
int ways(int type, int remV, int remK) {
    if (found) return 1; // stop if found
    if (remV == 0) {
        found = 1;
        return 1;                      // one way, use nothing
    }
    if ((remV < 0) || (type == N) || (remK == 0)) return 0;      // invalid or done
    int &ans = memo[type][remV][remK];
    if (ans != -1) return ans;                     // was computed before
    return ans = ways(type + 1, remV, remK) +             // ignore this type
                 ways(type, remV - coinValue[type], remK - 1);// one more of this type
}

// almost time limit... seems like top down is slow?!
// something like this would be better: https://www.codeproject.com/Articles/5290098/Using-Bottom-Up-Dynamic-Programming-to-Solve-the-C
// can just break once minCoins is not inf

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> S, S) {
        cin >> cases;
        vector<stampSet> stampSets;
        for (int i = 0; i < cases; i++) {
            cin >> N;
            for (int j = 0; j < N; j++) cin >> coinValue[j];
            stampSet tmp;
            tmp.numStamps = N;
            for (int j = N - 1; j >= 0; j--) {
                tmp.stamps.push_back(coinValue[j]);
            }
            memset(memo, -1, sizeof memo); // reset for each stamp set
            int maxCoverage = 0;
            while (true) {
                found = 0;
                if (ways(0, maxCoverage, S) > 0) {
                    maxCoverage++;
                } else {
                    maxCoverage--;
                    break;
                }
            }
            tmp.maxCov = maxCoverage;
            stampSets.push_back(tmp);
        }
        sort(stampSets.begin(), stampSets.end());
        cout << "max coverage = " << setw(3) << stampSets[0].maxCov << " :";
        for (int i = stampSets[0].numStamps - 1; i >= 0; --i) {
            if (i) cout << setw(3) << stampSets[0].stamps[i];
            else cout << setw(3) << stampSets[0].stamps[i] << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
