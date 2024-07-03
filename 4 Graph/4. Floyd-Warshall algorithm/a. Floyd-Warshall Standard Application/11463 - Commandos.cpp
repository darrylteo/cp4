#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

// dijkstra from start and target node would also work and find worst (start - building[i]) + (end - building[i])

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++ cases) {
        int n, m;
        cin >> n >> m;
        int grid[n][n];
        memset(grid, 0xf, sizeof(grid));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            grid[u][v] = 1;
            grid[v][u] = 1;
        }
        for (int i = 0; i < n; i++) {
            grid[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
        int ans = 0, s, t;
        cin >> s >> t;
	// trick to understand the question.
	// we have inf commandos, each go start-building[i]-end. find slowest commando
        for (int i = 0; i < n; i++) {
            ans = max(ans, grid[s][i] + grid[i][t]);
        }
        cout << "Case " << cases << ": " << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
