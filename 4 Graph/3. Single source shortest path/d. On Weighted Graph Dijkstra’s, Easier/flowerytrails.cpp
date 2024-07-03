#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int usedTrail[250005], ans;
vector<pair<int, vector<iii>>> parent;

inline void dfs(int u) {
    if (u == 0) return;
    for (auto &[v, w, idx]: parent[u].second) {
        if (usedTrail[idx]) continue;
        usedTrail[idx] = 1;
        ans += w; // new trail to plant flowers
        dfs(v);
    }
}

// quite tedious for 3.5 mark question on kattis
// note that modified Dijkstra's algorithm will TLE as it might visit same edge many many times if equal cost
//    1   4   7
//   / \ / \ / \
//  0   3   6   9
//   \ / \ / \ /
//    2   5   8
// there are 2^3 paths to go 9 if all legs cost 1. if same pattern then disaster ensues.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<viii> AL(n, viii()); // v, w, id
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(v, w, i);
        AL[v].emplace_back(u, w, i);
    }

    vi dist(n, 1e9);
    dist[0] = 0;
    memset(usedTrail, 0, sizeof usedTrail);
    ans = 0;
    parent.assign(n, {1e9, viii()});


    // original Dijkstra's algorithm
    set<ii> pq;
    for (int i = 0; i < n; i++) pq.emplace(dist[i], i); // sort by (d, u)

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto &[v, w, idx]: AL[u]) {                 // all edges from u
            if (dist[u] + w > dist[v]) continue;        // not improving, skip
            pq.erase({dist[v], v});                     // erase old pair
            dist[v] = dist[u] + w;                       // relax operation
            pq.insert({dist[v], v});                     // update the pair
            if (parent[v].first > dist[v]) { // replace parent
                parent[v].first = dist[v];
                parent[v].second.clear();
                parent[v].second.emplace_back(u, w, idx);
            } else if (parent[v].first == dist[v]) {
                parent[v].second.emplace_back(u, w, idx);
            }
        }
    }

    dfs(n - 1);
    cout << ans * 2 << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}