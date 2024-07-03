#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adjDag;
int memo[1005];

int countPaths(int u) {
    if (u == 1) return 1; // end at home
    if (memo[u] != 0) return memo[u];
    int res = 0;
    for (int v : adjDag[u]) {
        res += countPaths(v);
    }
    return memo[u] = res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> V >> E, V) {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        dist[1] = 0; // now home at node 1, office at 0
        st.insert({0, 1});
        while (!st.empty()) {
            auto [d, u] = *st.begin();
            st.erase(st.begin());
            for (auto &[v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    st.erase({dist[v], v});
                    dist[v] = dist[u] + w;
                    st.insert({dist[v], v});
                }
            }
        }
        adjDag.assign(V, vector<int>());
        for (int u = 0; u < V; u++) {
            for (auto &[v, w] : adj[u]) {
                if (dist[v] < dist[u]) adjDag[u].push_back(v); // if nearer to home, can move here
            }
        }
        memset(memo, 0, sizeof(memo));
        cout << countPaths(0) << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

