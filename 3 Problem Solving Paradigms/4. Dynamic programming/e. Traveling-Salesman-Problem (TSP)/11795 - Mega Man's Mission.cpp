// Collecting Beepers

#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

const int MAX_n = 17;
int can[MAX_n];
long long memo[MAX_n][1 << (MAX_n - 1)]; // Karel + max 10 beepers

// can will be 0 if he cannot go from u to v, and 1 otherwise
// when can cover all robots, return ways = 1
long long dp(int u, int mask, int weapons) {                        // mask = free coordinates, weapons = all usable weapons
    if (mask == 0) return 1;                       // managed to kill all robots
    long long &ans = memo[u][mask];
    if (ans != -1) return ans;                     // computed before
    int m = mask;
    long long tmpAns = 0;
    while (m) {
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v) + 1;          // offset v by +1. // ctz = count trailing zeros
        // check if any previous weapons or weapon gained from killing u can kill robot v
        if ((can[u] | weapons) & (1 << v)) {
            tmpAns += dp(v, mask ^ two_pow_v, weapons | can[u]); // ok, and gain weapon from killing u
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
        memset(can, 0, sizeof can);
        memset(memo, -1, sizeof memo);
        int N;
        cin >> N;
        string s;
        cin >> s; // our 1st set of weapons
        int weapon = 0;
        for (int i = 0; i < N; ++i) {
            if (s[i] == '1') weapon |= (1 << (i + 1));
        }
        for (int i = 0; i < N; ++i) {
            cin >> s; // record down other weapons
            for (int j = 0; j < N; ++j) {
                if (s[j] == '1') can[i + 1] |= (1 << (j + 1));
            }
        }

        cout << "Case " << cases << ": " << dp(0, (1 << N) - 1, weapon) << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}