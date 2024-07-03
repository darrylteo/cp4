#include <bits/stdc++.h>

using namespace std;

int memo[10005][105], visited[10005][105], a, b, c, tc = 1;

inline int dp(int k, int d) {
    if (k <= 0) return false;
    if (d <= 0) return k == 1; // the only possible way the recursion terminates is k == 1
    if (visited[k][d] == tc) return memo[k][d];
    visited[k][d] = tc;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < b; ++j) {
            if (dp(k - a - j, d - 1 - i)) return memo[k][d] = true;
        }
    }
    return memo[k][d] = false;
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_8_Advanced_Topics/8.3_DP_Techniques/kattis_recursionrandfun.cpp
// smart way of formulating state space as (k, d) where the state is true iff we can have f(d) = k.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int i, k;
    while (cin >> a >> b >> c >> i >> k) {
        cout << (dp(k, i) ? "possible\n" : "impossible\n");
        tc++;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
