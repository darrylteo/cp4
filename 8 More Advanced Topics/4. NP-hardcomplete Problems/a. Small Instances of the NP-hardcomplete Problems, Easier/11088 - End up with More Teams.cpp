#include <bits/stdc++.h>

using namespace std;

int N;
int ab[15], memo[1<<16]; // ab for ability. memo to record best so far given current bitset. 1 means not picked yet

int dp(int mask) {
    if (__builtin_popcount(mask) < 3) return 0; // a team needs exactly 3 members
    if (memo[mask] != -1) return memo[mask];

    int ans = 0;
    for (int p1 = 0; p1 < N; ++p1) if (mask & (1 << p1)) {
        for (int p2 = p1+1; p2 < N; ++p2) if (mask & (1 << p2)) {
            for (int p3 = p2+1; p3 < N; ++p3) if (mask & (1 << p3)) {
                int newMask = mask ^ (1 << p1) ^ (1 << p2) ^ (1 << p3);
                int prom = (ab[p1]+ab[p2]+ab[p3] >= 20) ? 1 : 0;
                ans = max(ans, prom + dp(newMask));
            }
        }
    }
    return memo[mask] = ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 1;
    while (cin >> N, N) {
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < N; ++i) cin >> ab[i];
        cout << "Case " << cases++ << ": " << dp((1 << N) - 1) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}