#include <bits/stdc++.h>

using namespace std;

struct path {
    int v;
    double temp, w;
};

int V, E, s, t;
vector<vector<path>> adj;

bool ok(double temp) {
    vector<int> vis(V + 1, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &e: adj[u]) {
            if (e.temp <= temp && !vis[e.v]) {
                vis[e.v] = 1;
                q.push(e.v);
            }
        }
    }
    return vis[t];
}

// 1. BSTA the temp and check if reachable using bfs
// 2. dijkstra to get shortest path and print the path

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> V >> E >> s >> t) {
        adj = vector<vector<path>>(V + 1);
        for (int i = 0; i < E; i++) {
            int u, v;
            double temp, w;
            cin >> u >> v >> temp >> w;
            adj[u].push_back({v, temp, w});
            adj[v].push_back({u, temp, w});
        }
        // find min temp
        double l = 0, r = 100;
        while (abs(l - r) > 1e-6) {
            double mid = (l + r) / 2;
            if (ok(mid)) r = mid;
            else l = mid;
        }

        vector<int> parent(V + 1, -1);
        vector<double> dist(V + 1, 1e9);
        set<pair<double, int>> st;
        dist[s] = 0;
        st.insert({0, s});
        while (!st.empty()) {
            auto [d, u] = *st.begin();
            st.erase(st.begin());
            for (auto &e: adj[u]) {
                if (e.temp <= r && dist[e.v] > d + e.w) {
                    st.erase({dist[e.v], e.v});
                    dist[e.v] = d + e.w;
                    parent[e.v] = u;
                    st.insert({dist[e.v], e.v});
                }
            }
        }
        if (dist[t] == 1e9) cout << "No Path\n";
        else {
            vector<int> path;
            for (int u = t; u != -1; u = parent[u]) path.push_back(u);
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i + 1 < path.size()) cout << " ";
            }
            cout << "\n";
        }
        cout << fixed << setprecision(1) << dist[t] << " " << r << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}