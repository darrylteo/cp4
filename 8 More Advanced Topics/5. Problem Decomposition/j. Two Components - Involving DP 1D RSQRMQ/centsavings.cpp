#include <bits/stdc++.h>

using namespace std;

int n, d;
vector<int> cum;
int memo[2005][25]; // idx, d_left

int dp(int idx, int d_left) {
    if (idx == n) return 0;
    if (d_left == 0) {
        int cost = cum[n] - cum[idx];
        int rem = cost % 10;
        if (rem < 5) cost -= rem;
        else cost += 10 - rem;
        return cost;
    }
    if (memo[idx][d_left] != -1) return memo[idx][d_left];
    int ans = INT_MAX;
    for (int i = idx + 1; i <= n; i++) {
        int cost = cum[i] - cum[idx];
        int rem = cost % 10;
        if (rem < 5) cost -= rem;
        else cost += 10 - rem;
        ans = min(ans, cost + dp(i, d_left - 1));
    }
    return memo[idx][d_left] = ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    cum.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cum[i];
        cum[i] += cum[i - 1];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, d) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

