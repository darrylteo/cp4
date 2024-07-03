#include <bits/stdc++.h>

using namespace std;

// tricky qn. the counterexample given at https://yp155136codingarea.blogspot.com/2016/11/uva-10805-cockroach-escape-networks.html
// 6 5
// 0 1
// 0 2
// 0 3
// 3 4
// 3 5
// points to the fact that when 2 nodes are a possible root, the sum of 2 longest edge would be greater if we do it normally by 1
// as it needs to be symmetrical about the root. with normal implementation, only symmetrical when answers are even
// so we need to add nodes in between so that we can get symmetrical answers (min of 2 longest paths will be even), then divide by 2.
// we have m "intermediate" nodes

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Case #" << cases << ":\n";
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dist(n + m, vector<int>(n + m));
        for (int i = 0; i < n + m; ++i) {
            for (int j = 0; j < n + m; ++j)
                dist[i][j] = 1e9;
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            dist[u][n + i] = dist[n + i][u] = 1;
            dist[v][n + i] = dist[n + i][v] = 1;
        }
        for (int k = 0; k < n + m; ++k) {
            for (int i = 0; i < n + m; ++i) {
                for (int j = 0; j < n + m; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int best = 1e9;
        for (int i = 0; i < n + m; ++i) {
            vector<int> d = dist[i];
            sort(d.begin(), d.begin() + n); // no need visit intermediate nodes
            int cur = d[n - 1] + d[n - 2];
            best = min(best, cur);
        }

        cout << best / 2 << "\n\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
