#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q, s;
    while (cin >> n >> m >> q >> s, n) {
        vector<vii> AL(n, vii());
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
        }

        vi dist(n, 1e9);
        dist[s] = 0;

        // (Modified) Dijkstra's algorithm
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, s}); // dist, vertex

        // sort the pairs by non-decreasing distance from s
        while (!pq.empty()) {                          // main loop
            auto [d, u] = pq.top();
            pq.pop();            // shortest unvisited u
            if (d > dist[u]) continue;                   // a very important check
            for (auto &[v, w]: AL[u]) {                 // all edges from u
                if (dist[u] + w >= dist[v]) continue;        // not improving, skip
                dist[v] = dist[u] + w;                       // relax operation
                pq.push({dist[v], v});                     // enqueue better pair
            }
        }

        for (int i = 0; i < q; i++) {
            int v;
            cin >> v;
            if (dist[v] == 1e9) {
                cout << "Impossible" << endl;
            } else {
                cout << dist[v] << endl;
            }
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}