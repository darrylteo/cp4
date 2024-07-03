#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> adj[100001];
ll N; // end point
ll maxDist;

ll dijkstra(ll length) { // length of longest allowed edge
    set<pair<ll, ll>> s;
    vector<ll> dist(100001, 1e18);
    s.insert({0, 1});
    dist[1] = 0;
    while (!s.empty()) {
        auto [d, u] = *s.begin();
        s.erase(s.begin());
        for (auto [v, w]: adj[u]) {
            if (dist[v] > d + w && w <= length) {
                s.erase({dist[v], v});
                dist[v] = d + w;
                s.insert({dist[v], v});
            }
        }
    }
    return dist[N];
}

// BSTA the temp and check if reachable using bfs
// note: large limits qn

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, X;
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    maxDist = dijkstra(1e18);
    maxDist = maxDist * (100 + X) / 100.0 + 1e-6;
    ll l = 1, r = 1e18;
    while (l < r) {
        ll mid = (r + l) / 2;
        if (dijkstra(mid) <= maxDist) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}