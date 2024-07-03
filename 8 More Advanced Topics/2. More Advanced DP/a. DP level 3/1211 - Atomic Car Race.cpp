#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int r;
        double b, v, e, f;
        cin >> b >> r >> v >> e >> f;
        vector<double> T(10001, 0);
        for (int x = 1; x <= 10000; x++) { // careful here it's x to x+1 but T[x] indexes from time to reach x
            if (x > r) T[x] = T[x - 1] + 1.0 / (v - e * (x - 1 - r));
            else T[x] = T[x - 1] + 1.0 / (v - f * (r - x + 1));
        }
        vector<double> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) dp[i] = T[a[i]]; // initialize assuming no tire change
        for (int i = 1; i <= n; i++) { // for each checkpoint
            for (int j = 1; j < i; j++) { // check all previous checkpoint. what if we changed tire there
                dp[i] = min(dp[i], dp[j] + T[a[i] - a[j]] + b);
            }
        }
        cout << fixed << setprecision(4) << dp[n] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


