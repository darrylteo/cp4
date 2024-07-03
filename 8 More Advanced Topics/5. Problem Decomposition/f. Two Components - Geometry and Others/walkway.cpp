#include <bits/stdc++.h>

using namespace std;

// vertices are parallel sides rather than the tile

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        int a, b, h;
        vector<pair<int, double>> adj[1005];
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> h;
            double cost = h * (b + a) / 2.0 * 0.02;
            adj[a].emplace_back(b, cost);
            adj[b].emplace_back(a, cost);
        }
        int s, t;
        cin >> s >> t;
        vector<double> dist(1005, 1e9);
        dist[s] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        cout << fixed << setprecision(2) << dist[t] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}