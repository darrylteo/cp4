#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & (-S))
#define inf 1000000000

int V, E;
int dist[17][17]; // 0 is start, 16 is end (regardless how many ppl). for tsp
int tspMemo[17][1 << 15]; // current node, mask of free coordinates
int carMemo[4][1 << 15]; // car remaining, mask of free coordinates

int tsp(int u, int mask) { // mask = free coordinates
    if (mask == 0) return dist[u][V + 1]; // go to end
    int &ans = tspMemo[u][mask];
    if (ans != -1) return ans; // computed before
    ans = inf;
    int m = mask;
    while (m) { // up to O(n)
        int two_pow_v = LSOne(m); // but this is fast
        int v = __builtin_ctz(two_pow_v) + 1; // offset v by +1
        ans = min(ans, 5 + dist[u][v] + tsp(v, mask ^ two_pow_v)); // keep the min
        m -= two_pow_v;
    }
    return ans;
}

int car(int rem, int mask) {
    if (mask == 0) return 0; // no more ppl
    if (rem == 0) return inf; // no more car but still ppl
    if (rem * 5 < __builtin_popcount(mask)) return inf; // not enough cars (5 ppl per car)
    int &ans = carMemo[rem][mask];
    if (ans != -1) return ans; // computed before
    ans = inf;
    for (int m = mask; m; m = (m - 1) & mask) { // picks subset of mask
        if (__builtin_popcount(m) > 5 || __builtin_popcount(m) == 0) continue; // 1 car = 1 to 5 ppl
        ans = min(ans, max(tsp(0, m), car(rem - 1, mask ^ m))); // 1 less car and remove m ppl from mask
    }
    return ans;
}

// floyd to reduce problem to tsp
// do 1 dfs to place ppl in cars
// internal tsp to find best route for current car
// weird that m<=1000... max 17 nodes so max roads should be 17*16/2 = 136... maybe repeated roads are given?

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    for (int i = 0; i < V + 2; i++)
        for (int j = 0; j < V + 2; j++)
            dist[i][j] = inf;
    for (int i = 0; i < V + 2; i++) dist[i][i] = 0;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = min(dist[u][v], w); // in case of repeated roads
    }
    // floyd
    for (int k = 0; k < V + 2; k++)
        for (int i = 0; i < V + 2; i++)
            for (int j = 0; j < V + 2; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    // ans
    memset(tspMemo, -1, sizeof tspMemo);
    memset(carMemo, -1, sizeof carMemo);
    cout << car(ceil(V / 5.0), (1 << V) - 1) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
