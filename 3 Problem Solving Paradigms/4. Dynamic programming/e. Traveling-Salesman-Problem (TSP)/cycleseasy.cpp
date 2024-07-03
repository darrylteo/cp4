// Collecting Beepers

#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

const int MAX_n = 11;
int can[MAX_n][MAX_n];
long long memo[MAX_n][1 << (MAX_n - 1)]; // Karel + max 10 beepers

// can will be 0 if he cannot go from u to v, and 1 otherwise
// when can cover all robots, return ways = 1
long long dp(int u, int mask) {                        // mask = free coordinates, weapons = all usable weapons
    if (mask == 0) return 1;                       // managed to kill all robots
    long long &ans = memo[u][mask];
    if (ans != -1) return ans;                     // computed before
    int m = mask;
    long long tmpAns = 0;
    while (m) {
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v) + 1;          // offset v by +1. // ctz = count trailing zeros
        // check if u can go to v && make sure if last leg, is ok too
        int flag = 0;
        if ((mask ^ two_pow_v) == 0 && !can[v][0]) flag = 1;
        if (can[u][v] && !flag) {
            tmpAns += dp(v, mask ^ two_pow_v); // ok, and gain weapon from killing u
        }
        m -= two_pow_v;
    }
    ans = max(ans, tmpAns);
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n, k;
        cin >> n >> k;
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < MAX_n; ++i) {
            for (int j = 0; j < MAX_n; ++j) {
                can[i][j] = 1;
            }
        }

        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            can[x][y] = 0;
            can[y][x] = 0;
        }

        cout << "Case #" << cases << ": " << (dp(0, (1 << (n-1)) - 1) / 2)%9901 << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}