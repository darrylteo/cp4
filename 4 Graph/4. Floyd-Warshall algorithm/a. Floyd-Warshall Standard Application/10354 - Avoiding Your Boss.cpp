#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

vector<vi> parent;
vi toRemove;

inline void dfs(int u, int last) {
    toRemove[u] = 1;
    if (u == last) return;
    for (auto &v: parent[u]) {
        dfs(v, last);
    }
}

// i prefer dijkstra when finding parents

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, bs, bt, ps, pt; // vertices, edges, boss start, target, person start, target
    while (cin >> n >> m >> bs >> bt >> ps >> pt) {
        n++; // 1-based
        vector<vii> AL(n, vii()); // v, w, id
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
        }

        vi dist(n, 1e9);
        dist[bs] = 0; // boss start
        toRemove.assign(n, 0);
        parent.assign(n, vi());

        // original Dijkstra's algorithm
        set<ii> pq;
        for (int i = 0; i < n; i++) pq.emplace(dist[i], i); // sort by (d, u)

        // sort the pairs by non-decreasing distance from s
        while (!pq.empty()) {                          // main loop
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            for (auto &[v, w]: AL[u]) {                 // all edges from u
                if (dist[u] + w > dist[v]) continue;        // not improving, skip
                if (dist[u] + w < dist[v]) { // replace parent
                    parent[v].clear();
                    parent[v].emplace_back(u);
                } else if (dist[u] + w == dist[v]) {
                    parent[v].emplace_back(u);
                }
                pq.erase({dist[v], v});                     // erase old pair
                dist[v] = dist[u] + w;                       // relax operation
                pq.insert({dist[v], v});                     // update the pair
            }
        }

        dfs(bt, bs); // remove all paths from boss to target

        // redo. just copy paste from above and add skips
        dist.assign(n, 1e9);
        dist[ps] = 0; // person start
        parent.assign(n, vi());

        // original Dijkstra's algorithm
        for (int i = 0; i < n; i++) pq.emplace(dist[i], i); // sort by (d, u)

        // sort the pairs by non-decreasing distance from s
        while (!pq.empty()) {                          // main loop
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            if (toRemove[u]) continue; // skip if u is removed
            for (auto &[v, w]: AL[u]) {                 // all edges from u
                if (toRemove[v]) continue; // skip if v is removed
                if (dist[u] + w > dist[v]) continue;        // not improving, skip
                if (dist[u] + w < dist[v]) { // replace parent
                    parent[v].clear();
                    parent[v].emplace_back(u);
                } else if (dist[u] + w == dist[v]) {
                    parent[v].emplace_back(u);
                }
                pq.erase({dist[v], v});                     // erase old pair
                dist[v] = dist[u] + w;                       // relax operation
                pq.insert({dist[v], v});                     // update the pair
            }
        }

        if (dist[pt] == 1e9 || toRemove[pt]) {
            cout << "MISSION IMPOSSIBLE." << endl;
        } else {
            cout << dist[pt] << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
