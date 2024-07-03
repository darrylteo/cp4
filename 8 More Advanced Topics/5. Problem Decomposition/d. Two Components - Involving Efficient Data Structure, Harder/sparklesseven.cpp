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

string ponies[7] = {"Twilight Sparkle", "Applejack", "Rarity", "Pinkie Pie", "Fluttershy", "Rainbow Dash", "Spike"};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<vector<int>> adj(7);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            int x;
            cin >> x;
            if (x) adj[i].push_back(j);
        }
    }

    for (int op = 1; op <= 7; ++op) {
        max_flow mf(7 + 7 + 2); // 0-6 ponies, 7-13 jobs
        int s = 14, t = 15;
        for (int i = 0; i < 7; i++)  mf.add_edge(s, i, op); // goes on up to op number of operations
        for (int i = 0; i < 7; i++)  mf.add_edge(i + 7, t, 1); // each job can be done only once
        for (int i = 0; i < 7; i++) {
            for (int j: adj[i]) mf.add_edge(i, j + 7, 1); // pony i can do job j
        }
        if (mf.dinic(s, t) == 7) {
            cout << op << "\n";
            vector<vector<int>> jobsDone(7); // jobs done by each pony
            for (int i = 0; i < 7; i++) { // each pony
                for (int j: mf.AL[i]) {
                    auto &[v, cap, flow, uu] = mf.EL[j];
                    if (flow && v < 14) jobsDone[i].push_back(v - 7);
                }
            }
            for (int i = 1; i <= op; i++) {
                vector<int> poniesAtOp; // ponies at operation i
                for (int j = 0; j < 7; j++) { // if have at least i jobs done means it's part of this operation
                    if (jobsDone[j].size() >= i) poniesAtOp.push_back(j);
                }
                cout << poniesAtOp.size() << '\n';
                for (int j: poniesAtOp) cout << ponies[j] << ' ' << jobsDone[j][i - 1] + 1 << '\n';
            }
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
