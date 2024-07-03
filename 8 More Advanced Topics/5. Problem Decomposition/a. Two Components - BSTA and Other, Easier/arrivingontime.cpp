#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct path {
    int v, t0, p, t;
};

vector<path> adj[100001];
ll N;
ll maxDist;

ll dijkstra(ll start) {
    set<pair<ll, ll>> s;
    vector<ll> dist(N, 1e18);
    s.insert({start, 0});
    dist[0] = start;
    // t0+x*p >= d ...
    while (!s.empty()) {
        auto [d, u] = *s.begin(); // d is curr time
        s.erase(s.begin());
        if (u == N - 1) return d;
        for (auto [v, t0, p, t]: adj[u]) {
            ll nextTime;
            if (d <= t0) nextTime = t0 + t;
            else nextTime = (ll) ceil((double) (d - t0) / p) * p + t0 + t;
            if (dist[v] > nextTime) {
                s.erase({dist[v], v});
                dist[v] = nextTime;
                s.insert({dist[v], v});
            }
        }
    }
    return dist[N - 1];
}

// BSTA the temp and check if reachable using bfs
// note: large limits qn
// grr wasted time debugging and realized that the travels are not bidirectional =.=

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m, s;
    cin >> N >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v, t0, p, t;
        cin >> u >> v >> t0 >> p >> t;
        adj[u].push_back({v, t0, p, t});
    }
    if (dijkstra(0) > s) {
        cout << "impossible";
        return 0;
    }
    ll l = 0, r = s;
    while (l < r - 1) {
        ll mid = (r + l) / 2;
        if (dijkstra(mid) > s) r = mid - 1;
        else l = mid;
    }
    if (dijkstra(r) <= s) cout << r;
    else cout << l;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}