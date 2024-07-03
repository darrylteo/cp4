#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll, int> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;                             // large enough

class max_flow {
public:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t) {                       // find augmenting path
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1});                       // record BFS sp tree
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break;                         // stop as sink t reached
            for (auto &idx: AL[u]) {                  // explore neighbors of u
                auto &[v, cap, flow, uu] = EL[idx];          // stored in EL[idx]
                if ((cap - flow > 0) && (d[v] == -1))      // positive residual edge
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        return d[t] != -1;                           // has an augmenting path
    }

    ll send_one_flow(int s, int t, ll f = INF) {   // send one flow from s->t
        if (s == t) return f;                        // bottleneck edge f found
        auto &[u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap - flow));
        flow += pushed;
        auto &rflow = get<2>(EL[idx ^ 1]);             // back edge
        rflow -= pushed;                             // back flow
        return pushed;
    }

    ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int) AL[u].size(); ++i) { // from last edge
            auto &[v, cap, flow, uu] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue;              // not part of layer graph
            if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i] ^ 1]);     // back edge
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    max_flow(int initialV) : V(initialV) {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                          // safeguard: no self loop
        EL.emplace_back(v, w, 0, u);                    // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1);                // remember this index
        EL.emplace_back(u, directed ? 0 : w, 0, v);     // back edge
        AL[v].push_back(EL.size() - 1);                // remember this index
    }

    ll edmonds_karp(int s, int t) {
        ll mf = 0;                                   // mf stands for max_flow
        while (BFS(s, t)) {                          // an O(V*E^2) algorithm
            ll f = send_one_flow(s, t);                // find and send 1 flow f
            if (f == 0) break;                         // if f == 0, stop
            mf += f;                                   // if f > 0, add to mf
        }
        return mf;
    }

    ll dinic(int s, int t) {
        ll mf = 0;                                   // mf stands for max_flow
        while (BFS(s, t)) {                          // an O(V^2*E) algorithm
            last.assign(V, 0);                         // important speedup
            while (ll f = DFS(s, t))                   // exhaust blocking flow
                mf += f;
        }
        return mf;
    }
};

// 0 - 1999: indv.
// 2000 - 3999: corp.
// 4000 - 5999: laws.
// 6000: source. 6001: sink.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, S, L;
    cin >> R >> S >> L;
    int s = 6000, t = 6001;
    vector<pair<int, int>> laws(L);
    for (int i = 0; i < L; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        laws[i] = {a, b};
    }
    int l = 0, r = L;

    while (l < r) {
        max_flow mf(6002);
        int m = (l + r) / 2;
        for (int i = 0; i < R; i++) mf.add_edge(s, i, m); // up to m flow to each individual
        for (int i = 0; i < S; i++) mf.add_edge(s, 2000 + i, m); // up to m flow to each corporation
        for (int i = 0; i < L; i++) mf.add_edge(4000 + i, t, 1); // each law has 1 flow
        for (int i = 0; i < L; i++) {
            mf.add_edge(laws[i].first, 4000 + i, 1); // individual to law
            mf.add_edge(2000 + laws[i].second, 4000 + i, 1); // corp to law
        }
        if (mf.dinic(s, t) == L) r = m;
        else l = m + 1;
    }

    max_flow mf(6002);
    int m = l;
    for (int i = 0; i < R; i++) mf.add_edge(s, i, m); // up to m flow to each individual
    for (int i = 0; i < S; i++) mf.add_edge(s, 2000 + i, m); // up to m flow to each corporation
    for (int i = 0; i < L; i++) mf.add_edge(4000 + i, t, 1); // each law has 1 flow
    for (int i = 0; i < L; i++) {
        mf.add_edge(laws[i].first, 4000 + i, 1); // individual to law
        mf.add_edge(2000 + laws[i].second, 4000 + i, 1); // corp to law
    }
    mf.dinic(s, t);

    vector<int> winners(L, -1);
    for (auto el: mf.EL) {
        auto [v, cap, flow, u] = el;
        if (v >= 4000 && v < 6000 && flow == 1) winners[v - 4000] = u;
    }
    for (int i = 0; i < L; i++) {
        if (winners[i] < 2000) cout << "INDV " << winners[i] + 1 << "\n";
        else cout << "CORP " << winners[i] - 2000 + 1 << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
