#include <bits/stdc++.h>

using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

// push relabel from same website got TLE and MLE ...
// algorithm from: https://cp-algorithms.com/graph/dinic.html
// more of a modelling exercise than push-relabel, since any max flow algorithm (using template) would work
// we model the maximum time as K, since from eqn, all robots have different starting point, but everything is multiples of k after

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V, K, E;
    cin >> V >> K >> E;
    int n = V * K + 2;
    int s = n - 2, t = n - 1; // super source/sink
    Dinic g(n, s, t);
    for (int v = 0; v < V; ++v) { // for each vertex
        int idx = v * K; // e.g. node 0 time 0 = 0. node 0 time 1 = 1. node v time i = v * K + i
        if (v < K) { // source to vertex, at time v.
            g.add_edge(s, idx + (v % K), 1);
        }
        if (v == V - 1) { // vertex to sink, at all time
            for (int i = 0; i < K; ++i) g.add_edge(idx + i, t, 1e9);
        }
    }
    while (E--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int uIdx = u * K, vIdx = v * K;
        for (int i = 0; i < K; ++i) g.add_edge(uIdx + i, vIdx + (i + 1) % K, 1); // add edge to v, with increment time
    }
    cout << g.flow() << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
