#include <bits/stdc++.h>

using namespace std;

// difficult to understand where the inclusion exclusion principle is used
// ref: https://www.cnblogs.com/zhexipinnong/p/3420455.html


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c[4], d[4], N, q, v;
    cin >> N;
    while (N--) {
        for (int &i: c) cin >> i;
        long long dp[100005];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; // all 0 except dp[0] = 1 for finding ways, all infinite except dp[0] = 0 for finding min
        for (int i: c) {
            for (int j = i; j <= 100000; ++j) {
                dp[j] += dp[j - i];
            }
        }

        cin >> q;
        while (q--) {
            for (int &i: d) cin >> i;
            cin >> v;
            long long ans = 0;
            for (int i = 0; i < 16; ++i) {
                int sign = 1, sum = 0;
                for (int j = 0; j < 4; ++j) {
                    if (i & (1 << j)) {
                        sign *= -1;
                        sum += (d[j] + 1) * c[j];
                    }
                }
                if (v - sum >= 0) ans += sign * dp[v - sum];
            }
            cout << ans << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
