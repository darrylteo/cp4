#include <bits/stdc++.h>

using namespace std;

vector<int> P;
int dp[15][15];

int dfs(int i, int j) {
    if (i + 1 == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for (int k = i + 1; k < j; ++k) {
        ans = min(ans, dfs(i, k) + dfs(k, j) + P[i] * P[k] * P[j]);
    }
    return dp[i][j] = ans;
}

void print(int i, int j) {
    if (i + 1 == j) cout << "A" << i + 1;
    int ans = dp[i][j];
    for (int k = i + 1; k < j; ++k) {
        if (dfs(i, k) + dfs(k, j) + P[i] * P[k] * P[j] == ans) {
            if (i + 1 != k) cout << "(";
            print(i, k);
            if (i + 1 != k) cout << ")";
            cout << " x ";
            if (k + 1 != j) cout << "(";
            print(k, j);
            if (k + 1 != j)cout << ")";
            return; // in case multiple routes could achieve optimal value
        }
    }
}

// even though cat(10) = 16796. it's better to practice dp.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, cases = 1;
    while (cin >> n, n) {
        cout << "Case " << cases++ << ": ";
        P.resize(n + 1);
        cin >> P[0];
        for (int i = 1; i < n; ++i) cin >> P[i] >> P[i];
        cin >> P[n];
        memset(dp, -1, sizeof(dp));
        dfs(0, n);
        cout << "(";
        print(0, n);
        cout << ")\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}