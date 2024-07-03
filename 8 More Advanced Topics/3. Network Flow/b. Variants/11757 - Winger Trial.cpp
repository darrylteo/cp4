#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e15;                             // large enough

class max_flow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t) {  // find augmenting path
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1});  // record BFS sp tree
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break;                                    // stop as sink t reached
            for (auto &idx: AL[u]) {                             // explore neighbors of u
                auto &[v, cap, flow] = EL[idx];                   // stored in EL[idx]
                if ((cap - flow > 0) && (d[v] == -1))             // positive residual edge
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};  // 3 lines in one!
            }
        }
        return d[t] != -1;  // has an augmenting path
    }

    ll DFS(int u, int t, ll f = INF) {  // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int) AL[u].size(); ++i) {  // from last edge
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue;  // not part of layer graph
            if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i] ^ 1]);  // back edge
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
        if (u == v) return;                       // safeguard: no self loop
        EL.emplace_back(v, w, 0);                 // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1);           // remember this index
        EL.emplace_back(u, directed ? 0 : w, 0);  // back edge
        AL[v].push_back(EL.size() - 1);           // remember this index
    }

    ll dinic(int s, int t) {
        ll mf = 0;                    // mf stands for max_flow
        while (BFS(s, t)) {           // an O(V^2*E) algorithm
            last.assign(V, 0);        // important speedup
            while (ll f = DFS(s, t))  // exhaust blocking flow
                mf += f;
        }
        return mf;
    }
};

// not obvious how to model, but it's max flow because we can just count how much "flow" from top to bottom
// flow here means the robot circle touch each other.
// let top be source and bottom be sink. from sample input, the first robot touches top,
// and the second robot touches first robot and third robot touches bottom and second robot
// so the flow is 1. i.e. there is 1 completely blocked column.
// robot is constrained node, so do the usual input output node splitting

struct point {
    int x, y;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int L, W, N, d, cases = 1;
    while (cin >> L >> W >> N >> d, L) {
        max_flow mf(2 * N + 2);
        int s = 2 * N, t = 2 * N + 1;
        vector<point> robos(N);
        for (int i = 0; i < N; i++) cin >> robos[i].x >> robos[i].y;
        for (int i = 0; i < N; i++) {
            mf.add_edge(i, i + N, 1); // input to output (i.e. get tackled only 1 time per robo)
            if (robos[i].y <= d) mf.add_edge(s, i, 1); // touch top
            if (W - robos[i].y <= d) mf.add_edge(i + N, t, 1); // touch bottom
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if ((robos[i].x - robos[j].x) * (robos[i].x - robos[j].x) +
                    (robos[i].y - robos[j].y) * (robos[i].y - robos[j].y) <= 4 * d * d) {
                    mf.add_edge(i + N, j, 1); // touch other robo
                }
            }
        }
        cout << "Case " << cases++ << ": " << mf.dinic(s, t) << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


