#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct state {
    ll dist, node, tix;

    bool operator<(const state &other) const {
        if (dist != other.dist) return dist < other.dist; // less distance is preferred
        if (tix != other.tix) return tix > other.tix; // 1 ticket remaining is better than 0 tickets
        return node < other.node; // doesn't matter
    }
};

// recycle from 10269 - Adventure of Super Mario except new limits. i set at 1e15 -_- bruh

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    // (node, weight). adjFast is for using tix.
    vector<vector<pair<ll, ll>>> adjNorm(n), adjFast(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adjNorm[u].emplace_back(v, w);
        adjNorm[v].emplace_back(u, w);
    }
    for (ll i = 0; i < f; ++i) {
        ll u, v;
        cin >> u >> v;
        adjFast[u].emplace_back(v, 0);
    }

    // starts at s and ends at t with 1 ticket to use
    set<state> pq;
    pq.insert({0, s, 1});
    vector<vector<ll>> dist(n, vector<ll>(2, 1e15));
    dist[s][1] = dist[s][0] = 0;
    while (!pq.empty()) {
        auto top = *pq.begin();
        pq.erase(pq.begin());
        ll d = top.dist, u = top.node, b = top.tix;
        if (u == t) {
            cout << d << endl;
            return 0;
        }
        if (dist[u][b] < d) continue;
        for (auto [v,w]: adjNorm[u]) { // normal dijkstra stuff
            if (d + w < dist[v][b]) {
                dist[v][b] = d + w;
                pq.insert({dist[v][b], v, b});
            }
        }
        if (b > 0) { // if we have tix, we can use them
            for (auto [v,w]: adjFast[u]) { // possible places to visit using tix
                if (d + w < dist[v][b-1]) { // use 1 tix
                    dist[v][b - 1] = d + w; // w is 0
                    pq.insert({dist[v][b - 1], v, b - 1});
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
