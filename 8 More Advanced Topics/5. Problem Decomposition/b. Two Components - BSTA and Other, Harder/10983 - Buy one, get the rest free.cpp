#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;                             // large enough

class max_flow {
private:
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
                auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
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
            auto &[v, cap, flow] = EL[AL[u][i]];
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

public:
    max_flow(int initialV) : V(initialV) {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                          // safeguard: no self loop
        EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1);                // remember this index
        EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
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

struct flight{
    int u, v, c, p, e;
};

int n, d, m;
vector<int> start;
vector<flight> flights;

ll getFlow(int maxPrice) {
    // already added +1 to d since it's day 0 to day d (original).
    // 0 to d - 1 is city 0, day 0 to d-1. d to 2d - 1 is city 1, day 0 to d-1 etc.
    max_flow mf(n * d + 2);
    int s = n * d, t = n * d + 1;
    // add edges from sink to each city at day 0
    for (int i = 0; i < n; i++) mf.add_edge(s, i * d, start[i]);
    // add from each city to itself +time (stay still)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d - 1; j++) {
            mf.add_edge(i * d + j, i * d + j + 1, INF);
        }
    }
    // last city to sink
    mf.add_edge((n - 1) * d + d - 1, t, INF);
    // for each plane price p below max price, add edge from city u to city v, time e to e + 1, capacity c
    for (int i = 0; i < m; i++) {
        if (maxPrice >= flights[i].p) {
            mf.add_edge(flights[i].u * d + flights[i].e, flights[i].v * d + flights[i].e + 1, flights[i].c);
        }
    }
    return mf.dinic(s, t);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cin >> n >> d >> m;
        d++;
        start.resize(n);
        flights.resize(m);
        for (int i = 0; i < m; ++i) {
            int u, v, c, p, e;
            cin >> u >> v >> c >> p >> e;
            u--; v--;
            flights[i] = {u, v, c, p, e};
        }
        for (int i = 0; i < n; ++i) cin >> start[i];
        int total = accumulate(start.begin(), start.end(), 0);
        int l = 0, r = 1000000000;
        while (l < r) {
            int mid = (l + r) / 2;
            if (getFlow(mid) == total) r = mid;
            else l = mid + 1;
        }
        cout << "Case #" << cases << ": ";
        if (l == 1000000000) cout << "Impossible\n";
        else cout << l << "\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
