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

// each point (x,y) is node[x+y*C] in the graph. we will do 0-based indexing
// again face problem since node capacitated not edge
// split nodes into 2 nodes, one for in and one for out
// let input be 0 to R*C-1, output be R*C to 2*R*C-1
// halfway i confused myself and ended up have to swap x and y. more used to rows and cols ._.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C;
        max_flow mf(2 * R * C + 2);
        int s = 2 * R * C, t = 2 * R * C + 1, OFFSET = R * C;
        // corners have 2 flow
        mf.add_edge(OFFSET + 0, t, 2);
        mf.add_edge(OFFSET + C - 1, t, 2);
        mf.add_edge(OFFSET + (R - 1) * C, t, 2);
        mf.add_edge(OFFSET + R * C - 1, t, 2);
        // sides have 1 flow
        for (int i = 1; i < C - 1; i++) {
            mf.add_edge(OFFSET + i, t, 1); // bottom
            mf.add_edge(OFFSET + (R - 1) * C + i, t, 1); // top
        }
        for (int i = 1; i < R - 1; i++) {
            mf.add_edge(OFFSET + i * C, t, 1); // left
            mf.add_edge(OFFSET + (i + 1) * C - 1, t, 1); // right
        }
        // inside flow to other vertices it touches
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int u = i * C + j;
                if (i > 0) mf.add_edge(OFFSET + u, (i - 1) * C + j, 1);
                if (i < R - 1) mf.add_edge(OFFSET + u, (i + 1) * C + j, 1);
                if (j > 0) mf.add_edge(OFFSET + u, i * C + j - 1, 1);
                if (j < C - 1) mf.add_edge(OFFSET + u, i * C + j + 1, 1);
            }
        }
        // all input to output
        // only allow 1 flow per node (input might be up to 4, so we block it here)
        for (int i = 0; i < R * C; i++) mf.add_edge(i, OFFSET + i, 1);
        // source to input
        int B;
        cin >> B;
        for (int i = 0; i < B; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            swap(x, y);
            mf.add_edge(s, x + y * C, 1);
        }
        cout << (mf.dinic(s, t) == B ? "possible" : "not possible") << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
