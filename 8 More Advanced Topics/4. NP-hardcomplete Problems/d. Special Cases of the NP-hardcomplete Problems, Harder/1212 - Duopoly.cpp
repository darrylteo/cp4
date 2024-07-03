#include <bits/stdc++.h>

using namespace std;

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

// book "The MWIS of this Bipartite Graph is the weight of all vertex costs minus the max flow value of this flow graph"
// company A left, company B right. it gets a inf edge if they have same node
// e.g. node 1 points to node 4 since both contain channel 1
//
//   /(cap45) 1 --- (capINF) 4\(cap54)
// S -(cap51) 2 --- (capINF) 5\(cap15) T
//   \(cap62) 3 --- (capINF) 6/(cap33)
//                           7/(cap2)
// max flow = 45 + 15 + 33 = 93
// total cap - max flow = 169... matches sample input
// note make sure fast... udebug only gives test case with N<100 but qn up to 3000
// use map rather than vector and check in O(N^2 * 32^2) time.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        if (cases > 1) cout << '\n';
        max_flow mf(6000 + 2); // 3000 for A, 3000 for B, 1 source, 1 sink
        map<int, int> channelsA;
        int s = 6000, t = 6001;
        int N, w, ch, total = 0;
        cin >> N >> ws;
        for (int i = 0; i < N; ++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            ss >> w;
            total += w;
            mf.add_edge(s, i, w);
            while (ss >> ch) channelsA[ch] = i;
        }
        cin >> N >> ws;
        for (int i = 0; i < N; ++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            ss >> w;
            total += w;
            mf.add_edge(i + 3000, t, w);
            while (ss >> ch) {
                if (channelsA.find(ch) != channelsA.end()) {
                    mf.add_edge(channelsA[ch], i + 3000, INF);
                }
            }
        }
        cout << "Case " << cases << ":\n" << total - mf.dinic(s, t) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}