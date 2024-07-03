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

// source (cap: 1)-> *
// */.out (cap: 1)-> .in (cap: 1)-> .out
// #/@ (cap: INF)-> .in (cap: 1)-> .out
// #/@ (cap: INF)-> #/@
// */.out (cap: 1)-> #/@
// # (cap: P)-> sink
// 0-899 *, 900-1799 .in, 1800-2699 .out, 2700-3599 #, 3600-4499 @, 4500 source, 4501 sink.
// pos will follow i * C + j

#define IN 900
#define OUT 1800
#define HASH 2700
#define AT 3600

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, P;
    while (cin >> R >> C >> P) {
        vector<string> grid(R);
        for (int i = 0; i < R; i++) cin >> grid[i];
        max_flow mf(4502);
        int s = 4500, t = 4501;
        // everything here
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '*') { // sink->*, *->.in/#/@
                    mf.add_edge(s, i * C + j, 1);
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dirr[k], nj = j + dirc[k];
                        if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                        if (grid[ni][nj] == '.') mf.add_edge(i * C + j, IN + ni * C + nj, 1);
                        else if (grid[ni][nj] == '#') mf.add_edge(i * C + j, HASH + ni * C + nj, 1);
                        else if (grid[ni][nj] == '@') mf.add_edge(i * C + j, AT + ni * C + nj, 1);
                    }
                } else if (grid[i][j] == '.') { // .in->.out, .out->.in/#/@
                    mf.add_edge(IN + i * C + j, OUT + i * C + j, 1);
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dirr[k], nj = j + dirc[k];
                        if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                        if (grid[ni][nj] == '.') mf.add_edge(OUT + i * C + j, IN + ni * C + nj, 1);
                        else if (grid[ni][nj] == '#') mf.add_edge(OUT + i * C + j, HASH + ni * C + nj, 1);
                        else if (grid[ni][nj] == '@') mf.add_edge(OUT + i * C + j, AT + ni * C + nj, 1);
                    }
                } else if (grid[i][j] == '#') { // #->sink, #->.in/#/@
                    mf.add_edge(HASH + i * C + j, t, P);
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dirr[k], nj = j + dirc[k];
                        if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                        if (grid[ni][nj] == '.') mf.add_edge(HASH + i * C + j, IN + ni * C + nj, 1);
                        else if (grid[ni][nj] == '#') mf.add_edge(HASH + i * C + j, HASH + ni * C + nj, INF);
                        else if (grid[ni][nj] == '@') mf.add_edge(HASH + i * C + j, AT + ni * C + nj, INF);
                    }
                } else if (grid[i][j] == '@') { // @->.in/#/@
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dirr[k], nj = j + dirc[k];
                        if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                        if (grid[ni][nj] == '.') mf.add_edge(AT + i * C + j, IN + ni * C + nj, 1);
                        else if (grid[ni][nj] == '#') mf.add_edge(AT + i * C + j, HASH + ni * C + nj, INF);
                        else if (grid[ni][nj] == '@') mf.add_edge(AT + i * C + j, AT + ni * C + nj, INF);
                    }
                }
            }
        }
        cout << mf.dinic(s, t) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
