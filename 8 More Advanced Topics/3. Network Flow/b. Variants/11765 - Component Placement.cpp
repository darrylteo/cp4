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

// first part is easier to get. just point source to top, and bottom to sink. this will take the min of top and bottom.
// the key idea once you get told it's a max flow, is to add more edges since it constrains the flow
// second part if u draw for last case for sample input, just the first 2 nodes

//     s
// INF   6
//  8    7
//     t
// we will pick 8 and 7 for a cost of 15. but how did we get here? let right node = R, left = L
// s -> R -> t (6 flow) // standard min from first part
// s -> L -> t (8 flow)
// up to here, R -> t has 6/7 flow.
// s -> L -> R -> t (1 flow)
// we pay the cost of bottom bottom = 15
// if the 7 node become 200, we start picking the opposite side cost of 8 + 6 + 10 = 24 (bottom top and payment)

// not obvious, BUT if someone told u is max flow and u got 1st part, 2nd part can be guessed out...かもしれない


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> top(N), bottom(N);
        for (int i = 0; i < N; i++) cin >> top[i];
        for (int i = 0; i < N; i++) cin >> bottom[i];
        max_flow mf(N + 2);
        int s = N, t = N + 1;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x == -1) {
                mf.add_edge(s, i, INF);
                mf.add_edge(i, t, bottom[i]);
            } else if (x == 1) {
                mf.add_edge(s, i, top[i]);
                mf.add_edge(i, t, INF);
            } else {
                mf.add_edge(s, i, top[i]);
                mf.add_edge(i, t, bottom[i]);
            }
        }
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            mf.add_edge(u, v, w);
            mf.add_edge(v, u, w);
        }
        cout << mf.dinic(s, t) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


