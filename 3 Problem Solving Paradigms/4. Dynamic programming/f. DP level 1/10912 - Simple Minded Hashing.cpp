#include <bits/stdc++.h>

using namespace std;

// sort of trick qn for initializing array size. int i actually can't go above 26 ('z') so sum can't go above 351
int L, S, memo[30][30][400];

// again kinda slow using top down approach. most ppl use bottom up is faster..

int dp(int i, int last, int sum) {
    if (sum > S) return 0;
    if (i == L) {
        if (sum == S) return 1;
        return 0;
    }
    if (memo[i][last][sum] != -1) return memo[i][last][sum];
    int ans = 0;
    for (int j = last + 1; j <= 26; j++) {
        if (sum + j <= S) {
            ans += dp(i + 1, j, sum + j);
        }
    }
    return memo[i][last][sum] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (cin >> L >> S, L != 0 || S != 0) {
        if (L > 26 || S > 351) {
            cout << "Case " << cases++ << ": " << 0 << '\n';
            continue;
        }
        int ans = 0;
        memset(memo, -1, sizeof memo);
        ans = dp(0, 0, 0);
        cout << "Case " << cases++ << ": " << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}