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

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};

// compared to previous few, this is easier. maybe since it came just after the question 11765 - Component Placement
// where we learnt that adding more edges actually constrains the flow further.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    max_flow mf(2 * R * C + 2);
    int s = 2 * R * C, t = 2 * R * C + 1;
    vector<vector<int>> grid(R, vector<int>(C)); // 0 to R*C-1 are input, R*C to 2*R*C-1 are output
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }
    // all (output) nodes on sides point to sink
    for (int i = 0; i < R; ++i) {
        mf.add_edge(R * C + i * C, t, INF); // left
        mf.add_edge(R * C + (i + 1) * C - 1, t, INF); // right
    }
    for (int i = 0; i < C; ++i) {
        mf.add_edge(R * C + i, t, INF); // top
        mf.add_edge(R * C + C * (R - 1) + i, t, INF); // bot
    }
    // all (input) nodes point to (output) nodes (constraint on nodes)
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            mf.add_edge(i * C + j, R * C + i * C + j, grid[i][j]);
        }
    }
    // all (output) nodes point to (input) nodes if touching each other from sides
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nr = i + dirr[k], nc = j + dirc[k];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                mf.add_edge(R * C + i * C + j, nr * C + nc, INF);
            }
        }
    }
    int r, c;
    cin >> r >> c;
    mf.add_edge(s, r * C + c, INF); // this means it's possible to just defend the square where castle is.
    cout << mf.dinic(s, t) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}