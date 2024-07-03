#include <bits/stdc++.h>

using namespace std;

#define BIG 1e8
#define LSOne(S) (S & (-S))

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi dist;
vi memo;

int dp(int mask) {
    if (mask == 0) return 0;
    if (memo[mask] != -1) return memo[mask];
    int ans = BIG;
    int two_pow_p1 = LSOne(mask);                  // speedup
    int p1 = __builtin_ctz(two_pow_p1);            // p1 is first on bit
    int m = mask-two_pow_p1;                       // turn off bit p1
    while (m) {
        int two_pow_p2 = LSOne(m);                   // then, try to match p1
        int p2 = __builtin_ctz(two_pow_p2);          // with another on bit p2
        ans = min(ans, dist[p1][p2] + dp(mask^two_pow_p1^two_pow_p2));
        m -= two_pow_p2;                             // turn off bit p2
    }
    return memo[mask] = ans;
}

// direct implementation of chinese postman problem

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // get initial graph 1st
    int V, E;
    while (cin >> V >> E, V) {
        vi deg(V, 0);
        vvi g(V, vector<int>(V, BIG));
        int sum = 0;
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            sum += w;
            u--, v--;
            deg[u]++, deg[v]++;
            g[u][v] = g[v][u] = min(g[u][v], w);
        }
        // get shortest dist
        vvi floyd = g;
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                }
            }
        }
        // contract graph to only those with odd degree (there will be even number of them)
        vi nodes;
        for (int i = 0; i < V; i++) {
            if (deg[i] % 2) nodes.push_back(i);
        }
        dist.assign(nodes.size(), vector<int>(nodes.size(), BIG));
        for (int i = 0; i < nodes.size(); i++) {
            dist[i][i] = 0;
            for (int j = i + 1; j < nodes.size(); j++) {
                dist[i][j] = dist[j][i] = floyd[nodes[i]][nodes[j]];
            }
        }
        // get minimum weight perfect matching
        memo.assign(1 << nodes.size(), -1);
        cout << sum + dp((1 << nodes.size()) - 1) << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
