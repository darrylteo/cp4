#include <bits/stdc++.h>

using namespace std;

// for each permutation of show times, for each importance, find sum of alignment times missed
// e.g. for 2nd case, 1: 30 60; 2: 15 45. time missed for 30 and 60 = missed[0], time missed for 15 and 45 = missed[1]

// VERY WEIRD ON https://www.udebug.com/UVa/234 !!! diff output (error values) but mine was accepted
// i manually checked for:
// 3 48 22 21
// 6 4 6 5 33 5 172 3 149 5 100 2 135
// 0
// soln should be 21 22 48 error 217 but it gave same permutation with error 208
// show cumtime: 21 43 91
// alignments: 6 33 172 149 100 135
// error = (21-6) + (43-33) + (172 - 91) + (149 - 91) + (100 - 91) + (135 - 91) = 217 not 208!!

// forgot to save this file but clion saved me!!! has local file history for past ~2 weeks :DDD

struct importance {
    int miss1, miss2, miss3, miss4, miss5;

    bool operator<(const importance &other) const {
        if (miss1 != other.miss1) {
            return miss1 < other.miss1;
        } else if (miss2 != other.miss2) {
            return miss2 < other.miss2;
        } else if (miss3 != other.miss3) {
            return miss3 < other.miss3;
        } else if (miss4 != other.miss4) {
            return miss4 < other.miss4;
        } else {
            return miss5 < other.miss5;
        }
    }

    int sum() const {
        return miss1 + miss2 + miss3 + miss4 + miss5;
    }
};

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cases = 1;
    while (cin >> n, n) {
        cout << "Data set " << cases++ << "\n";
        vector<int> shows(n);
        for (int i = 0; i < n; ++i) {
            cin >> shows[i];
        }
        sort(shows.begin(), shows.end()); // sort to get cumulative time

        int m;
        cin >> m;
        map<int, vector<int>> align; // each importance level has a vector of alignment points. check [0] to [4] later
        vector<int> missed(5);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            align[a - 1].push_back(b); // set importance level to 0-based
        }

        importance bestMissed = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}; // worst case
        vector<int> best;
        do {
            // get cumulative time
            vector<int> cumTime(n);
            int time = 0;
            for (int i = 0; i < n; ++i) {
                time += shows[i];
                cumTime[i] = time;
            }

            // for each importance, find sum of alignment times missed, can just iterate over all alignment points instead of lower bound
            for (int i = 0; i < 5; ++i) {
                int sum = 0;
                for (int j = 0; j < align[i].size(); ++j) {
                    int idx = lower_bound(cumTime.begin(), cumTime.end(), align[i][j]) - cumTime.begin();
                    if (idx == n) { // no show after alignment point
                        sum += align[i][j] - cumTime[idx - 1];
                    } else if (idx == 0) { // no show before alignment point
                        sum += cumTime[idx] - align[i][j];
                    } else { // show before and after alignment point
                        sum += min(align[i][j] - cumTime[idx - 1], cumTime[idx] - align[i][j]);
                    }
                }
                missed[i] = sum;
            }

            // compare with best
            importance currMissed = {missed[0], missed[1], missed[2], missed[3], missed[4]};
            if (currMissed < bestMissed) {
                bestMissed = currMissed;
                best = shows;
            }
        } while (next_permutation(shows.begin(), shows.end()));

        cout << "Order:";
        for (int i = 0; i < n; ++i) {
            cout << " " << best[i];
        }
        cout << "\nError: " << bestMissed.sum() << "\n";

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
