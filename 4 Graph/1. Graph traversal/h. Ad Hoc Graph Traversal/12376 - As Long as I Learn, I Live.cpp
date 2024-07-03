#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[105]; // v, learning units... remember to sort by learning units in descending order
int vis[105], learn[105], ans, nodeAns;

inline void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    ans += learn[u];
    if (adj[u].empty()) { // can't visit anything else
        nodeAns = u;
        return;
    }
    int next = adj[u][0].first;
    if (vis[next]) return; // also can't visit anything else
    dfs(next);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> learn[i];
            adj[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v, learn[v]);
        }


        for (int i = 0; i < n; ++i) {
            sort(adj[i].begin(), adj[i].end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second > b.second;
            });
        }

        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(0); // always starts from 0

        cout << "Case " << cases << ": " << ans << " " << nodeAns << "\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}