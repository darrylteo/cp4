#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll, ll> edge;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll INF = 1e18; // INF = 1e18, not 2^63-1 to avoid overflow

class min_cost_max_flow {
private:
    int V;
    ll total_cost;
    vector<edge> EL;
    vector<vi> AL;
    vll d;
    vi last, vis;

    bool SPFA(int s, int t) { // SPFA to find augmenting path in residual graph
        d.assign(V, INF);
        d[s] = 0;
        vis[s] = 1;
        queue<int> q({s});
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (auto &idx: AL[u]) {                  // explore neighbors of u
                auto &[v, cap, flow, cost] = EL[idx];          // stored in EL[idx]
                if ((cap - flow > 0) && (d[v] > d[u] + cost)) {      // positive residual edge
                    d[v] = d[u] + cost;
                    if (!vis[v]) q.push(v), vis[v] = 1;
                }
            }
        }
        return d[t] != INF;                           // has an augmenting path
    }

    ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        vis[u] = 1;
        for (int &i = last[u]; i < (int) AL[u].size(); ++i) { // from last edge
            auto &[v, cap, flow, cost] = EL[AL[u][i]];
            if (!vis[v] && d[v] == d[u] + cost) {                      // in current layer graph
                if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                    total_cost += pushed * cost;
                    flow += pushed;
                    auto &[rv, rcap, rflow, rcost] = EL[AL[u][i] ^ 1]; // back edge
                    rflow -= pushed;
                    vis[u] = 0;
                    return pushed;
                }
            }
        }
        vis[u] = 0;
        return 0;
    }

public:
    min_cost_max_flow(int initialV) : V(initialV), total_cost(0) {
        EL.clear();
        AL.assign(V, vi());
        vis.assign(V, 0);
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, ll c, bool directed = true) {
        if (u == v) return;                          // safeguard: no self loop
        EL.emplace_back(v, w, 0, c);                 // u->v, cap w, flow 0, cost c
        AL[u].push_back(EL.size() - 1);                // remember this index
        EL.emplace_back(u, 0, 0, -c);                // back edge
        AL[v].push_back(EL.size() - 1);                // remember this index
        if (!directed) add_edge(v, u, w, c);         // add again in reverse
    }

    pair<ll, ll> mcmf(int s, int t) {
        ll mf = 0;                                   // mf stands for max_flow
        while (SPFA(s, t)) {                          // an O(V^2*E) algorithm
            last.assign(V, 0);                         // important speedup
            while (ll f = DFS(s, t))                   // exhaust blocking flow
                mf += f;
        }
        return {mf, total_cost};
    }
};

struct linkTmp {
    int u, v;
    ll w;
};

// 2 cap from node 0 to node 1 and see if we end up with 2 flow at sink (V)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V, E;
    while (cin >> V >> E, V) {
        min_cost_max_flow mf(V+1);
        mf.add_edge(0, 1, 2, 0);
        while (E--) {
            int u, v, c;
            cin >> u >> v >> c;
            mf.add_edge(u, v, 1, c, false);
        }
        auto [flow, cost] = mf.mcmf(0, V);
        if (flow == 2) {
            cout << cost << endl;
        } else {
            cout << "Back to jail" << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
