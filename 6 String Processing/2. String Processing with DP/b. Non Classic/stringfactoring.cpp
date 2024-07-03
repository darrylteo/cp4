#include <bits/stdc++.h>

using namespace std;

int dp[205][205];
string query;

// true if s can be formed by repeating n times
bool canSubstr(string &s, int n) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (pos == n) pos = 0;
        if (s[i] != s[pos++]) return false;
    }
    return true;
}

int dfs(int l, int r) {
    if (l == r) return 1;
    if (dp[l][r] != 1e9) return dp[l][r];
    dp[l][r] = r - l + 1;
    for (int i = l; i < r; ++i) {
        dp[l][r] = min(dp[l][r], dfs(l, i) + dfs(i + 1, r));
    }
    string s = query.substr(l, r - l + 1);
    for (int i = 1; i < s.size(); ++i) {
        if (s.length() % i == 0) {
            if (canSubstr(s, i)) {
                dp[l][r] = min(dp[l][r], dfs(l, l + i - 1));
            }
        }
    }
    return dp[l][r];
}

// general idea for dp for substring [l, r]
// get min val of all (possible splits) and (reduced size factors)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> query;
    for (int i = 0; i < query.size(); ++i) {
        for (int j = 0; j < query.size(); ++j) {
            dp[i][j] = 1e9;
        }
    }
    cout << dfs(0, (int) query.size() - 1) << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}