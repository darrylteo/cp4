#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 35;
const int MAX_W = 10005;

// W is remaining value, K is remaining cnt of numbers
int N, k, V[MAX_N], weight, memo[MAX_N][MAX_W][MAX_N];

// rather than store best weight, memo stores the number of ways to get the final answer once we get to this point
int dp(int idx, int remW, int remK) {
    if (remW == 0 && remK == 0) return 1;
    if (idx == N || remW < 0 || remK < 0) return 0;
    if (memo[idx][remW][remK] != -1) return memo[idx][remW][remK];
    return memo[idx][remW][remK] = dp(idx + 1, remW, remK) + dp(idx + 1, remW - V[idx], remK - 1);
}

long long choose(int n, int x) {
    if (x == 0 || x == n) return 1;
    return (n * choose(n-1,x-1)) / x;
}

// similar to 1213 - Sum of Different Primes

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g;
    cin >> g;
    for (int games = 1; games <= g; ++games) {
        cout << "Game " << games << " -- ";
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> V[i];
        cin >> k >> weight;
        for (int i = 0; i < N; ++i) for (int j = 0; j <= weight; ++j) for (int l = 0; l <= k; ++l) memo[i][j][l] = -1;
        int ways = dp(0, weight, k);
        int totalWays = choose(N, k);
        cout << ways << " : " << totalWays - ways << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
