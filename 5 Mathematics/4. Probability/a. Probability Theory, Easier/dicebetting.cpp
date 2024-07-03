#include <bits/stdc++.h>

using namespace std;

int n, s, k;
double memo[10005][505]; // throws remaining, unique numbers cnt

inline double dp(int throws, int unique) {
    if (unique >= k) {
        return 1;
    }
    if (throws == 0 || throws < k - unique) {
        return 0;
    }
    if (memo[throws][unique] != -1) {
        return memo[throws][unique];
    }
    double ans = 0;
    ans += dp(throws - 1, unique) * (unique / (double) s);
    ans += dp(throws - 1, unique + 1) * ((s - unique) / (double) s);
    return memo[throws][unique] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> s >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            memo[i][j] = -1;
        }
    }
    cout << fixed << setprecision(9) << dp(n, 0) << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
