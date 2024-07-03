#include <bits/stdc++.h>

using namespace std;

// all[i]==1 if using all nodes turned on in i can connect to all other nodes
// memo[i] store maximum depth for bitmask i
// adj[i] store (in a bitset) nodes connected to i (including i)
int all[1 << 16], memo[1 << 16], adj[16], N;

int dp(int mask) {
    if (!mask) return 0;
    if (memo[mask] != -1) return memo[mask];
    int ans = 0;
    // poggers decrement suggested by copilot. turns off 1 or more bits of mask (lexicographically?)
    for (int i = mask; i; i = (i - 1) & mask) {
        if (all[i]) ans = max(ans, dp(mask ^ i) + 1);
    }
    return memo[mask] = ans;
}

// follow clue and get which combination of N nodes, when used, can connect to all other nodes

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (cin >> N, N) {
        memset(all, 0, sizeof all);
        memset(memo, -1, sizeof memo);
        memset(adj, 0, sizeof adj);
        for (int i = 0; i < N; i++) {
            adj[i] |= 1 << i; // include itself [i]
            int M, x;
            cin >> M;
            while (M--) {
                cin >> x;
                adj[i] |= 1 << x;
            }
        }
        int covAll = (1 << N) - 1;
        for (int i = 0; i < 1 << N; i++) { // for all possible combination of N nodes
            int cur = 0;
            for (int j = 0; j < N; j++) {
                if (i & 1 << j) cur |= adj[j];
            }
            all[i] = cur == covAll; // if all nodes are connected
        }
        cout << "Case " << cases++ << ": " << dp((1 << N) - 1) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
