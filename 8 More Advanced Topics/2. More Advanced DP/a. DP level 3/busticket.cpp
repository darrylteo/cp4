#include <bits/stdc++.h>

using namespace std;

// populate the table with all possible previous station to this station

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int s, p, m, n;
    cin >> s >> p >> m >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<long long> dp(n + 1, 1e15);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + s); // from prev to here
        int j = i - 1;
        while (j >= 1 && v[i] - v[j] < m) { // using a period ticket
            dp[i] = min(dp[i], dp[j - 1] + p); // -1 since u paid up to station j-1, then use period to travel inclusive j to i
            j--;
        }
    }
    cout << dp[n] << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


