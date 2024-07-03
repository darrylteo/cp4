#include <bits/stdc++.h>

using namespace std;

int dp[2000005], greedy[2000005], coins[105];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int &i: coins) cin >> i;
    int maxId = 2 * coins[n - 1];
    int flag = 0;
    for (int i = 0; i <= maxId; ++i) dp[i] = 1e6;
    dp[0] = 0;
    int ptr = 0;
    for (int i = 1; i <= maxId; ++i) {
        // coin change
        for (int j = 0; j < n && coins[j] <= i; ++j) {
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }

        // greedy. past a certain point u are just subtracting the largest coin
        while(ptr < n-1 && coins[ptr+1] <= i) {
            ptr++;
        }
        greedy[i] = greedy[i - coins[ptr]] + 1;

        // check if same
        if (greedy[i] != dp[i]) {
            flag = 1;
            break;
        }

    }

    if (flag) cout << "non-canonical" << endl;
    else cout << "canonical" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
