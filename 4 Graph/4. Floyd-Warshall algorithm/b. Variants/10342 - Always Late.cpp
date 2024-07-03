#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// challenging on how to find the second best path (online mostly use dijkstra)
// ref: https://blog.csdn.net/s_h_r/article/details/48519523
// floyd warshall can do it too.
// using the apsp from FW, dfs from s to t and choose path only if it is worse than FW, but better than current

// test is for dfs, grid is for FW
int test[100][100], grid[100][100], n, m, cases = 1;
vii adj[100];

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 1e9;
            test[i][j] = 1e9;
        }
        grid[i][i] = 0;
//        test[i][i] = 0; // IMPORTANT not to do. i suspect test case may have query with same junction and 0 would be wrong ans.
        adj[i].clear();
    }
}

void getInput() {
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        grid[u][v] = grid[v][u] = min(grid[u][v], w);
    }
}

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            }
        }
    }
}

inline void dfs(int s, int t, int u, int w) {
    // equal to best path... wrong
    if (test[s][t] <= w + grid[u][t]) return;
    // worse than original, but better than current. good
    if (w + grid[u][t] > grid[s][t] && w + grid[u][t] < test[s][t]) {
        test[s][t] = w + grid[u][t];
    }
    for (auto &v : adj[u]) {
        dfs(s, t, v.first, w + v.second);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        cout << "Set #" << cases++ << endl;
        reset();
        getInput();
        floydWarshall();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1e9) {
                    dfs(i, j, i, 0);
                }
            }
        }
        int q, s, t;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> s >> t;
            if (test[s][t] == 1e9) cout << "?\n";
            else cout << test[s][t] << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




