#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1
};

int dfsNumberCounter, numSCC;
vector<vi> AL;
vi dfs_num, dfs_low, visited, color;
stack<int> St;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;    // dfs_low[u]<=dfs_num[u]
    dfsNumberCounter++;                            // increase counter
    St.push(u);                                    // remember the order
    visited[u] = 1;
    for (int v: AL[u]) {
        if (dfs_num[v] == UNVISITED) tarjanSCC(v);
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {                // a root/start of an SCC
        ++numSCC;                                    // when recursion unwinds to u
        while (true) {
            int v = St.top();
            St.pop();
            visited[v] = 0;
            color[v] = numSCC - 1;  // 0 based index
            if (u == v) break;
        }
    }
}
int memo[1005];
int dfs(vi &clique, vector<vi> &ALSCC, int u) {
    if (memo[u] != -1) return memo[u];
    int ans = 0;
    for (int v: ALSCC[u]) {
        ans = max(ans, dfs(clique, ALSCC, v));
    }
    ans += clique[u];
    return memo[u] = ans;
}

// reading the question carefully, they are transforming a directed graph into its transistive closure.
// i.e. any point that can be reached, is connected.
// this means that for an SCC, all points are connected to each other directly/indirectly at first,
// but after transistive, all are connected directly i.e. it becomes a clique.
// all points in an SCC that is connected to another SCC, means they can be a clique too.
// e.g. points 1 2 3 clique, 4 5 6 clique, have directed edge from 3-4
// after transistive, all from 1 2 3 clique can reach all from 4 5 6 clique.
// so first reduce to SCC and then just dfs to find longest path on the SCC graph.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, T;
    cin >> T;
    while (T--) {
        cin >> V >> E;
        AL.assign(V, vi());
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            AL[u].emplace_back(v);
        }

        dfs_num.assign(V, UNVISITED);
        dfs_low.assign(V, 0);
        visited.assign(V, 0);
        color.assign(V, 0);
        while (!St.empty()) St.pop();
        dfsNumberCounter = numSCC = 0;
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < V; ++i) {
            if (dfs_num[i] == UNVISITED) {
                tarjanSCC(i);
            }
        }
        vector<int> clique(numSCC, 0); // size of clique
        for (int i = 0; i < V; ++i) clique[color[i]]++;
        vector<vector<int>> ALSCC(numSCC, vector<int>()); // contracted graph
        for (int i = 0; i < V; ++i) {
            for (int j: AL[i]) {
                if (color[i] != color[j]) {
                    ALSCC[color[i]].emplace_back(color[j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < numSCC; ++i) {
            ans = max(ans, dfs(clique, ALSCC, i));
        }
        cout << ans << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
