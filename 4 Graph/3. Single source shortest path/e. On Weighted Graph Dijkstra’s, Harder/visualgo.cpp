#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vii> AL(n, vii()); // v, w, id
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(v, w);
    }

    int s, t;
    cin >> s >> t;
    vi dist(n, 1e9), ways(n, 0);
    dist[s] = 0;
    ways[s] = 1;

    // original Dijkstra's algorithm
    set<ii> pq;
    for (int i = 0; i < n; i++) pq.emplace(dist[i], i); // sort by (d, u)

    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto &[v, w]: AL[u]) {
            if (dist[u] + w > dist[v]) continue;
            if (dist[u] + w < dist[v]) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
                ways[v] = ways[u];
            } else { // they are equal. don't need add to pq, just update ways
                ways[v] += ways[u];
            }
        }
    }

    cout << ways[t] << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}