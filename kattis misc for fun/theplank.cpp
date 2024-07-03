#include <bits/stdc++.h>

using namespace std;

int memo[30];

int dfs(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = dfs(n - 1) + dfs(n - 2) + dfs(n - 3);
}

// the babiest dp question so far

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << dfs(n) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}