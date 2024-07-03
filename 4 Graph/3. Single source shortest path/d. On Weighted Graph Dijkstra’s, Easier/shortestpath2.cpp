#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct edge {
    int v, t0, P, w;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q, s;
    while (cin >> n >> m >> q >> s, n) {
        vector<edge> AL[n];
        for (int i = 0; i < m; i++) {
            int u, v, t0, P, w;
            cin >> u >> v >> t0 >> P >> w;
            AL[u].push_back({v, t0, P, w});
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
            for (auto &[v, t0, P, w] : AL[u]) {
                if (P == 0 && t0 < dist[u]) continue; // missed crossing time
                if (t0 > dist[u]) {
                    if (dist[v] > t0 + w) { // wait until t0 then walk w units
                        dist[v] = t0 + w;
                        pq.push({dist[v], v});
                    }
                } else {
                    if (P == 0 && dist[u] != t0) continue; // missed crossing time
                    int k = ceil((double)(dist[u] - t0) / P); // wait until next available time
                    int t = t0 + k * P + w;
                    if (dist[v] > t) {
                        dist[v] = t;
                        pq.push({dist[v], v});
                    }
                }
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