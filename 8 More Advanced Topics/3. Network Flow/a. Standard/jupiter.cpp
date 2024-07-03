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

// source (cap: a1,as)-> sensors1 (no cap)-> queues1a (cap: c1,cq)-> queues1b(no cap)-> earth1 (cap: d)-> sink
// source (cap: a1,as)-> sensors2 (no cap)-> queues2a (cap: c1,cq)-> queues2b(no cap)-> earth1 (cap: d)-> sink
//                                      queues1b (no cap)-> queues2a (cap: c1,cq)
// etc. see whether sink can collect all the flow from source (sum of as)
// total nodes = n * s (sensor) + 2 * n * q (queue) + n (earth) + 2 (source, sink)
// in general, start id are sensors, +S to get queuea, +Q to get queueb, +1 to get earth (cumulative)

// feels like a lot of "important" information from qn can be ignored... here are some i ignored.
// 1. FIFO
// 2. A sensor can write data to the queue only if the queue has enough space left to take all the data; if not, the data is lost.
// 3. all queues have to be empty after the last downlink opportunity.
// 3rd point clearly no need follow since we allow flow from q1->q2->q3 etc and got AC. otherwise WA.
// maybe cuz the data was stored in the sensors for a long time... :S

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q, S;
    cin >> N >> Q >> S;
    const int s = 4998, t = 4999, SHIFT = S + 2 * Q + 1;
    max_flow mf(5000);
    for (int i = 0; i < S; i++) {
        int q;
        cin >> q;
        q--;
        for (int n = 0; n < N; n++) {
            mf.add_edge(n * SHIFT + i, n * SHIFT + S + q, INF); // sensor (no cap)-> queuea
        }
    }
    for (int q = 0; q < Q; q++) {
        int cq;
        cin >> cq;
        for (int n = 0; n < N; n++) {
            mf.add_edge(n * SHIFT + S + q, n * SHIFT + S + Q + q, cq); // queuea (cap: cq)-> queueb
            mf.add_edge(n * SHIFT + S + Q + q, n * SHIFT + S + 2 * Q + 1, INF); // queueb (no cap)-> earth
        }
    }
    // try add q1->q2->q3 etc.
    for (int n = 0; n < N - 1; ++n) {
        for (int q = 0; q < Q; ++q) {
            mf.add_edge(n * SHIFT + S + Q + q, (n + 1) * SHIFT + S + q, INF); // queues1b (no cap)-> queues2a
        }
    }
    int d, opt_flow = 0;
    for (int n = 0; n < N; n++) {
        cin >> d;
        mf.add_edge(n * SHIFT + S + 2 * Q + 1, t, d); // earth (cap: d)-> sink
        for (int ss = 0; ss < S; ss++) {
            int as;
            cin >> as;
            opt_flow += as;
            mf.add_edge(s, n * SHIFT + ss, as); // source (cap: a1,as)-> sensor
        }
    }

    cout << ((mf.dinic(s, t) == opt_flow) ? "possible" : "impossible") << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
