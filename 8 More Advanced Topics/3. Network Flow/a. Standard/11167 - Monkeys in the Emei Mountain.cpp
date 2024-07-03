#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, ll, ll, int> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;                             // large enough

class MaxFlow {
private:
    int n;
    vector<tuple<int, long long, long long>> edges; // (target node, capacity, flow used)
    vector<vector<int>> graph;
    vector<int> distance, last;

    bool bfs(int s, int t) { // construct level graph and check if more flow is possible
        distance.assign(n, -1);
        distance[s] = 0;
        queue<int> q({s});
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == t) { break; }
            for (int idx: graph[cur]) {
                auto &[v, cap, flow] = edges[idx];
                if ((cap - flow) > 0 && distance[v] == -1) {
                    q.push(v);
                    distance[v] = distance[cur] + 1;
                }
            }

        }
        return distance[t] != -1;

    }

    long long dfs(int cur, int t, long long f = 1e18) { // sends a single flow from s to t through level graph O(E)
        if (cur == t || f == 0) return f;
        for (int &i = last[cur]; i < (int) graph[cur].size(); ++i) {
            auto &[v, cap, flow] = edges[graph[cur][i]];
            if (distance[cur] != distance[v] - 1) continue;
            if (long long pushed = dfs(v, t, min(f, cap - flow))) {
                flow += pushed;
                long long &rflow = get<2>(edges[graph[cur][i] ^
                                                1]); // clever way to get back edge number^1 -> number +1 if number even else number -1
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

public:
    MaxFlow(int nodes) : n(nodes) {
        edges.clear();
        graph.assign(n, vector<int>());
    }

    void add_edge(int cur, int v, long long w, bool directed = true) {
        if (cur == v) { return; }
        edges.emplace_back(v, w, 0);
        graph[cur].push_back(edges.size() - 1);
        edges.emplace_back(cur, directed ? 0 : w, 0); // residual graph
        graph[v].push_back(edges.size() - 1);
    }

    long long dinic(int s, int t) {  // O(V* (E + VE)) = O(V^2 * E)
        // calculates the maxFlow from s to t
        long long maxFlow = 0;
        while (bfs(s, t)) { // O(E)
            last.assign(n, 0); // this remembers the index for the dfs
            while (long long flow = dfs(s, t)) { // O(E)
                maxFlow += flow;
            }
        }
        return maxFlow;
    }

    // lists all residual edges ({taret node, cap, flow}) of node cur, which have a flow<0 (that means dinic used the forward edge)
    vector<tuple<int, long long, long long>> get_used_residual_edges(int cur) {
        vector<tuple<int, long long, long long>> ret;
        for (int i = 0; i < (int) graph[cur].size(); ++i) {
            if (get<0>(edges[graph[cur][i]]) > cur)
                return ret; // first edgesa are residual edges, if node is bigger: only forward eges left.
            if (get<2>(edges[graph[cur][i]]) < 0)ret.push_back(edges[graph[cur][i]]);
            //cout << "cur: " << cur << ", Target: " << get<0>(edges[graph[cur][i]]) << ", cap: " << get<1>(edges[graph[cur][i]]) << ", flow: " << get<2>(edges[graph[cur][i]]) << endl;

        }
        return ret;
    }

    // lists all residual edges ({target node, cap, flow}) of node cur, which have a flow<0 (that means dinic used the forward edge)
    vector<tuple<int, long long, long long>> get_used_forward_edges(int cur) {
        // find first forward edge via binary search
        vector<tuple<int, long long, long long>> ret;
        auto itr = lower_bound(graph[cur].begin(), graph[cur].end(), cur,
                               [=](int left, int right) { return get<0>(edges[left]) < right; });
        int lb = itr - graph[cur].begin();

        for (int i = lb; i < (int) graph[cur].size(); ++i) {
            if (get<2>(edges[graph[cur][i]]) > 0)ret.push_back(edges[graph[cur][i]]);
            //cout << "Target: " << get<0>(edges[graph[cur][i]]) << ", cap: " << get<1>(edges[graph[cur][i]]) << ", flow: " << get<2>(edges[graph[cur][i]]) << endl;
        }
        return ret;
    }
};

struct monke {
    int l, r, w;
};

#define TM 50000 // time

// took this guys max flow since it's faster
// ref: https://github.com/dirkneuhaeuser/exercise-problems/blob/master/network_flow/standard/UVa11167_monkeys_in_the_emei.cpp#L99

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, s = TM + 499, t = TM + 498, cases = 1;
    while (cin >> n >> m, n) {
        MaxFlow mf(TM + 500); // 50000 time, 100 monke, 1 source, 1 sink
        vector<monke> monkes(n);
        int opt_flow = 0;
        for (int i = 0; i < n; ++i) {
            cin >> monkes[i].w >> monkes[i].l >> monkes[i].r;
            opt_flow += monkes[i].w;
            for (int j = monkes[i].l; j < monkes[i].r; ++j) {
                mf.add_edge(j, TM + i, 1);
            }
            mf.add_edge(TM + i, t, monkes[i].w);
        }
        for (int i = 0; i < TM; ++i) mf.add_edge(s, i, m);
        cout << "Case " << cases++ << ": ";
        if (mf.dinic(s, t) == opt_flow) { // done part 1
            cout << "Yes\n";
            for (int i = 0; i < n; ++i) {
                int start = -1, end = -1;
                vector<pair<int, int>> ans;
                auto edges = mf.get_used_residual_edges(TM + i);
                for (auto e: edges) {
                    int time = get<0>(e);
                    if (start == -1) {
                        start = time;
                        end = time + 1;
                    } else {
                        if (time == end) end++;
                        else {
                            ans.emplace_back(start, end);
                            start = time;
                            end = time + 1;
                        }
                    }
                }
                if (start != -1) ans.emplace_back(start, end);
                cout << ans.size();
                for (auto an: ans) {
                    cout << " (" << an.first << "," << an.second << ")";
                }
                cout << "\n";
            }
        } else cout << "No\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
