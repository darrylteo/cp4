#include <bits/stdc++.h>

using namespace std;

// important sentence: p and q friend && q and r friend => p and r friend
// means that if p can go q house, and q can go r house, then p can go r house, it will have a line in input for this.
// that's why clue is clique. i.e. if we process all of p neighbours, it is a disjoint clique.
// if clique size odd, impossible. else dp and find minimum weight matching. return impossible if clique odd size

int cost[200][200], costDfs[200][200], vis[200];
vector<int> adj[200], memo;
int V, E;

// same as uva 10911 Forming Quiz Teams
int dfs(int mask) {
    if (mask == 0) return 0;
    if (memo[mask] != -1) return memo[mask];
    int ans = 1e9;
    int p1 = __builtin_ctz(mask);
    int m = mask ^ (1 << p1);
    while (m) {
        int p2 = __builtin_ctz(m);
        m ^= (1 << p2);
        ans = min(ans, dfs(mask ^ (1 << p1) ^ (1 << p2)) + cost[p1][p2]);
    }
    return memo[mask] = ans;
}

int solve(int u) {
    vis[u] = 1;
    vector<int> clique;
    clique.push_back(u);
    for (int v : adj[u]) {
        clique.push_back(v);
        vis[v] = 1;
    }
    if (clique.size() % 2) return -1;
    for (int i = 0; i < clique.size(); i++) {
        for (int j = i + 1; j < clique.size(); j++) {
            cost[i][j] = cost[j][i] = costDfs[clique[i]][clique[j]];
        }
    }
    memo.assign(1 << clique.size(), -1);
    return dfs((1 << clique.size()) - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        costDfs[u][v] = costDfs[v][u] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            int res = solve(i);
            if (res == -1) {
                cout << "impossible" << endl;
                return 0;
            }
            ans += res;
        }
    }
    cout << ans << endl;
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

