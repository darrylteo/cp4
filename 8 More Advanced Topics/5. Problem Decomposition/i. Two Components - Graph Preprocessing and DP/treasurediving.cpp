#include <bits/stdc++.h>

using namespace std;

int dist[10][10]; // nodes are source and idols
int id; // number of idols

int backtrack(int mask, int last, int remAir) {
    if (remAir < dist[last][0]) return -1; // died. journey ended on prev cave
    int ans = 0;
    for (int i = 1; i <= id; i++) {
        if (mask & (1 << i)) {
            ans = max(ans, 1 + backtrack(mask ^ (1 << i), i, remAir - dist[last][i]));
        }
    }
    return ans;
}

// 8 idols only... reduce problem to source + idols.
// probably can't dp since very low probability of same mask last remAir. this is O(2^9 * 9 * 1000000) = 1.8e9
// if just backtrack it's O(9!) = 362880
// anyway probably the time consumed is the dijkstra.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        cin >> id;
        vector<int> nodes;
        nodes.resize(id+1);
        nodes[0] = 0;
        for (int i = 1; i <= id; i++) cin >> nodes[i];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                dist[i][j] = 1e9;
            }
            dist[i][i] = 0;
        }
        // for each node, need do dijkstra
        for (int i = 0; i <= id; i++) {
            int node = nodes[i];
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> ds(V, 1e9);
            pq.emplace(0, node); // distance, node
            ds[node] = 0;
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > ds[u]) continue;
                for (auto &[v, w]: adj[u]) {
                    if (ds[v] > ds[u] + w) {
                        ds[v] = ds[u] + w;
                        pq.emplace(ds[v], v);
                    }
                }
            }
            for (int j = 0; j <= id; j++) {
                dist[i][j] = dist[j][i] = ds[nodes[j]];
            }
        }
        int air;
        cin >> air;
        int ans = backtrack((1 << (id+1)) - 1, 0, air);
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

