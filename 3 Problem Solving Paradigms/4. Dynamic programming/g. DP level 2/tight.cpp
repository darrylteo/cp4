#include <bits/stdc++.h>

using namespace std;

double memo[105][15]; // length, last digit. store tight word cnt (divide total no. words)
int k, n;

double dp(int len, int last) {
    if (len == 0) {
        double ans = 1;
        for (int i = 0; i < n; ++i) {
            ans /= k + 1;
        }
        return ans;
    }
    if (memo[len][last] != -1) return memo[len][last];

    double ans = 0;
    for (int i = 0; i <= k; ++i) {
        if (i == last || i == last - 1 || i == last + 1) ans += dp(len - 1, i);
    }
    return memo[len][last] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> k >> n) {
        for (int i = 0; i < 105; ++i) {
            for (int j = 0; j < 15; ++j) {
                memo[i][j] = -1;
            }
        }

        double ans = 0;
        for (int i = 0; i <= k; ++i) {
            ans += dp(n - 1, i);
        }
        cout << fixed << setprecision(10) << ans * 100 << endl;


    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


