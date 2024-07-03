// SuperSale

// 0-1 Knapsack DP (Top-Down, faster)

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;
const int MAX_W = 40;

int N, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW) {
    if ((id == N) || (remW == 0)) return 0;        // two base cases
    int &ans = memo[id][remW];
    if (ans != -1) return ans;                     // computed before
    if (W[id] > remW) return ans = dp(id+1, remW); // no choice, skip
    return ans = max(dp(id+1, remW),               // has choice, skip
                     V[id]+dp(id+1, remW-W[id]));  // or take
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T; scanf("%d", &T);
    while (T--) {
        memset(memo, -1, sizeof memo);
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d %d", &V[i], &W[i]);
        int ans = 0;
        int G; scanf("%d", &G);
        while (G--) {
            int MW; scanf("%d", &MW);
            ans += dp(0, MW);
        }
        printf("%d\n", ans);
    }
    return 0;
}
