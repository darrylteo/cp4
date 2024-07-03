#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].emplace_back(b, d);
            adj[b].emplace_back(a, d);
        }
        // regular dijkstra
        set<pair<int, int>> pq;
        vector<int> dist(n + 1, 1e9);
        pq.insert({0, s});
        dist[s] = 0;
        while (!pq.empty()) {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            if (d > dist[u]) continue;
            for (auto [v,w] : adj[u]) {
                if (dist[v] > d + w) {
                    pq.erase({dist[v], v});
                    dist[v] = d + w;
                    pq.insert({dist[v], v});
                }
            }
        }
        // with check on g-h
        set<tuple<int, int, int>> pq2;
        vector<vector<int>> dist2(n+1, vector<int>(2, 1e9));
        pq2.insert({0, s, 0});
        dist2[s][0] = 0;
        while (!pq2.empty()) {
            auto [d, u, flag] = *pq2.begin();
            pq2.erase(pq2.begin());
            if (d > dist2[u][flag]) continue;
            for (auto [v,w] : adj[u]) {
                int new_flag = flag;
                if ((u == g && v == h) || (u == h && v == g)) new_flag = 1;
                if (dist2[v][new_flag] > d + w) {
                    pq2.erase({dist2[v][new_flag], v, new_flag});
                    dist2[v][new_flag] = d + w;
                    pq2.insert({dist2[v][new_flag], v, new_flag});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;
            if (dist[x] == dist2[x][1] && dist[x] < 1e9) ans.push_back(x); // same dist and reachable
        }
        sort(ans.begin(), ans.end());
        for (int i : ans) cout << i << " ";
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
