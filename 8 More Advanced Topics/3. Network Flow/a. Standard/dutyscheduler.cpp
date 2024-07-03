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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    max_flow mf(100); // 60 people, 31 days, 1 source, 1 sink
    int s = 98, t = 99, p, d;
    cin >> p >> d;
    map<int, string> names;
    for (int i = 0; i < p; i++) {
        string name;
        cin >> name;
        names[i] = name;
        int n;
        cin >> n;
        while (n--) {
            int day;
            cin >> day;
            day--;
            mf.add_edge(i, 60 + day, 1); // people to day
        }
    }
    for (int i = 0; i < d; i++) mf.add_edge(60 + i, t, 2); // 2 people can work on a day
    // test all possible "max days worked per person"
    for (int max_days = 1; max_days <= d; max_days++) {
        max_flow tmp_mf = mf;
        for (int i = 0; i < p; i++) tmp_mf.add_edge(s, i, max_days); // source to people
        if (tmp_mf.dinic(s, t) == 2 * d) { // 2 people per day
            cout << max_days << "\n";
            vector<vector<int>> ans(d, vector<int>());
            for (int i = 0; i < p; i++) {
                for (int j : tmp_mf.AL[i]) {
                    auto &[v, cap, flow, uu] = tmp_mf.EL[j];
                    if (v >= 60 && flow == 1) {
                        ans[v - 60].push_back(i); // person i works on day v-60
                    }
                }
            }
            for (int i = 0; i < d; i++) {
                cout << "Day " << i + 1 << ": ";
                for (int j : ans[i]) cout << names[j] << " ";
                cout << "\n";
            }
            break;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
