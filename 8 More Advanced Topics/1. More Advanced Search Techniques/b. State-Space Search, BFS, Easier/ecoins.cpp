#include <bits/stdc++.h>

using namespace std;

int m, S, S2;
int memo[305][305]; // [x][y] stores remaining steps to get feasible values of x and y. don't explore beyond S
vector<pair<int, int>> coins;

inline int dp(int x, int y) {
    if (x * x + y * y > S2) return 1e9;
    if (x * x + y * y == S2) return 0;
    if (memo[x][y] != -1) return memo[x][y];

    int ans = 1e9;
    for (auto & coin : coins) {
        ans = min(ans, dp(x + coin.first, y + coin.second) + 1);
    }

    return memo[x][y] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> m >> S;
        S2 = S * S;
        memset(memo, -1, sizeof(memo));
        coins.clear();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0 && y == 0) continue;
            coins.emplace_back(x, y);
        }
        if (dp(0, 0) >= 1e9) {
            cout << "not possible\n";
        } else {
            cout << dp(0, 0) << "\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}