#include <bits/stdc++.h>

using namespace std;

// learning bottom up

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long dp[90][2]; // level, 0 if branched, 1 if not branched
    dp[1][0] = 0; // no such state (first level was not branched)
    dp[1][1] = 1; // base case
    // for branched at i-1, dp[i-1][0]*2, half go to branched at i dp[i][0], half go to not branched at i dp[i][1]
    // for not branched at i-1, dp[i-1][1], all go to branched at i dp[i][0]
    for (int i = 2; i < 86; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    int n;
    while (cin >> n, n) {
        cout << dp[n][0] + dp[n][1] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

