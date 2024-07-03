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

    // if you are adding a bidirectional edge u<->v with weight cap into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll cap, ll cost, bool directed = true) {
        if (u == v) return;                          // safeguard: no self loop
        EL.emplace_back(v, cap, 0, cost);                 // u->v, cap cap, flow 0, cost cost
        AL[u].push_back(EL.size() - 1);                // remember this index
        EL.emplace_back(u, 0, 0, -cost);                // back edge
        AL[v].push_back(EL.size() - 1);                // remember this index
        if (!directed) add_edge(v, u, cap, cost);         // add again in reverse
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

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};
int R = 5, C;

int rci(int r, int c) { return r * C + c; } // row, col to idx

// in-nodes 0...N-1, out-nodes N...2N-1. source = 2N, sink = 2N+1
// in to out is 1 capacity, c cost, where c is the cell value.
// source to in is 1 capacity, 0 cost. out to sink is 1 capacity, 0 cost.
// any node out, to adjacent in, is inf capacity, 0 cost.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> C, C) {
        int N = R * C;
        min_cost_max_flow mcmf(2 * N + 2);
        int s = 2 * N, t = 2 * N + 1;
        vector<string> grid(R);
        for (int i = 0; i < R; i++) cin >> grid[i];
        // get the start points in col 0. connect them to source.
        for (int r = 0; r < R; r++) {
            if (grid[r][0] == '@') {
                int idx = rci(r, 0);
                mcmf.add_edge(s, idx, 1, 0);
            }
        }
        // all nodes in last col to sink.
        for (int r = 0; r < R; r++) {
            int idx = rci(r, C - 1);
            mcmf.add_edge(idx + N, t, 1, 0);
        }
        // connect in to out.
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int idx = rci(r, c);
                if (grid[r][c] == '@') mcmf.add_edge(idx, idx + N, 1, 0);
                else mcmf.add_edge(idx, idx + N, 1, grid[r][c] - '0');
            }
        }
        // connect out to in.
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                for (int d = 0; d < 4; d++) {
                    int nr = r + dirr[d], nc = c + dirc[d];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                        int idx1 = rci(r, c), idx2 = rci(nr, nc);
                        mcmf.add_edge(idx1 + N, idx2, INF, 0);
                    }
                }
            }
        }
        auto [mf, cost] = mcmf.mcmf(s, t);
        cout << cost << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
