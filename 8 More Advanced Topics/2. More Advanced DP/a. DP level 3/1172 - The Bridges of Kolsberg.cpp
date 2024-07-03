#include <bits/stdc++.h>

using namespace std;

struct soln {
    int val, num;
    bool operator<(const soln &rhs) const { // total value, number of bridges
        if (val == rhs.val) return num > rhs.num; // so that we pick less bridges using max()
        return val < rhs.val;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        map<string, int> idx;
        vector<vector<int>> osIdx(2), val(2, vector<int>(1000,0)); // [i][j]. i==0 for NORTH, i==1 for SOUTH
        vector<soln> dp(1000, {0,0}); // total value, number of bridges, when considering up to bridge j
        int n, m, id = 0;
        string s;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s >> s >> val[0][i];
            if (idx.find(s) == idx.end()) idx[s] = id++;
            osIdx[0].push_back(idx[s]);
        }
        cin >> m;
        if (m == 0) { // since m-1 out of bounds
            cout << "0 0\n";
            continue;
        }
        for (int i = 0; i < m; ++i) {
            cin >> s >> s >> val[1][i];
            if (idx.find(s) == idx.end()) idx[s] = id++;
            osIdx[1].push_back(idx[s]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) { // need reverse since we compare to j-1, when it does not use bridge i (prev iteration)
                if (osIdx[0][i] == osIdx[1][j]) {
                    soln tmp = {0,0}; // case for j = 0
                    if (j > 0) tmp = dp[j - 1]; // regular case
                    tmp.val += val[0][i] + val[1][j]; // add value of connection
                    tmp.num++; // add number of bridges
                    dp[j] = max(dp[j], tmp); // pick best
                }
            }
            for (int j = 1; j < m; ++j) dp[j] = max(dp[j], dp[j - 1]); // update dp
        }
        cout << dp[m - 1].val << " " << dp[m - 1].num << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


