#include <bits/stdc++.h>

using namespace std;

// find min position and check right-down diagonal. each time ok, size +1
// min position is lower_bound, either for each row or column. could do min of (row,col). optional

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m, n && m) {
        vector<vector<int>> v(n, vector<int>(m));
        for (auto &i: v) for (auto &j: i) cin >> j;
        int t, x, y;
        cin >> t;
        while (t--) {
            cin >> x >> y;
            int bestAns = 0;
            for (int i = 0; i < n; ++i) {
                auto it = lower_bound(v[i].begin(), v[i].end(), x); // lower bound only works on sorted containers
                if (it == v[i].end()) continue;
                int j = it - v[i].begin();
                int ans = bestAns; // tiny optimization
                while (i + ans < n && j + ans < m && v[i + ans][j + ans] <= y) ++ans;
                bestAns = max(bestAns, ans);
            }
            cout << bestAns << '\n';
        }
        cout << "-\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

