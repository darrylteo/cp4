#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    while (cin >> n >> m >> q) {
        if (n == 0 && m == 0 && q == 0) break;
        int grid[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1e9;
            }
        }
        for (int i = 0; i < n; i++) grid[i][i] = 0;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            grid[u][v] = min(grid[u][v], w); // incase of multiple edges and catch -ve edge into itself grid[i][i] < 0
        }
        for (int k = 0; k < n; k++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    if (grid[u][k] < 1e9 && grid[k][v] < 1e9) { // important check in case grid[u][v] == 1e9, grid[u][k] == 1e9, grid[k][v] < 0. might wrongly update
                        grid[u][v] = min(grid[u][v], grid[u][k] + grid[k][v]);
                    }
                }
            }
        }

        // check for negative cycles
        int isNegativeCycle[n];
        for (int i = 0; i < n; i++) isNegativeCycle[i] = 0;
        for (int i = 0; i < n; i++) if (grid[i][i] < 0) isNegativeCycle[i] = 1;

        for (int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v;
            bool inNeg = false;
            for (int k = 0; k < n; k++) {
                if (isNegativeCycle[k] && grid[u][k] < 1e9 && grid[k][v] < 1e9) {
                    inNeg = true;
                    break;
                }
            }
            if (inNeg) cout << "-Infinity" << endl;
            else if (grid[u][v] == 1e9) cout << "Impossible" << endl;
            else cout << grid[u][v] << endl;
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
