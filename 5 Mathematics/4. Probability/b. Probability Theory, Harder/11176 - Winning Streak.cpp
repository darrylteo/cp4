#include <bits/stdc++.h>

using namespace std;

// ref: https://lbv-pc.blogspot.com/2012/06/winning-streak.html
// challenging problem

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    double p;
    double memo[505][505], powers[505];
    while (cin >> n >> p, n) {
        powers[0] = 1;
        for (int i = 1; i <= n; i++) {
            powers[i] = powers[i - 1] * p;
        }

        for (int i = 0; i <= n; i++) {
            memo[0][i] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                memo[i][j] = memo[i - 1][j];
                if (j == i - 1) {
                    memo[i][j] -= powers[i];
                } else if (j < i - 1) {
                    memo[i][j] -= memo[i - j - 2][j] * (1 - p) * powers[j + 1];
                }
            }
        }

        double ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += (memo[n][i] - memo[n][i - 1]) * i;
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
