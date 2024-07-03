#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

// easy implement, hard come up with algorithm
// do forward and backward, then for each edge, see if cost from source + W + cost to destination is <= p.
// if ok can consider this edge for max cost

vector<int> dijkstra(vector<vii> &adj, int source) {
    int n = adj.size();
    vi dist(n, 1e8); // prevent overflow for "dist[u] + w + rdist[v] <= p"
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, source});
    dist[source] = 0;
    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, s, t, p;
        cin >> n >> m >> s >> t >> p;
        vector<vii> adj(n), radj(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
            radj[v].push_back({u, w});
        }
        vi dist = dijkstra(adj, s - 1);
        vi rdist = dijkstra(radj, t - 1);
        int max_cost = -1;
        for (int u = 0; u < n; u++) {
            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w + rdist[v] <= p) {
                    max_cost = max(max_cost, w);
                }
            }
        }
        cout << max_cost << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
