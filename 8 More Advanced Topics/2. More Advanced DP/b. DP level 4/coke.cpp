#include <bits/stdc++.h>

using namespace std;

int memo[155][155][55]; // cokes left, n5 left, n10 left. store num coins used

inline int dp(int cokes, int n1, int n5, int n10) {
    if (cokes == 0) return 0;
    int &ans = memo[cokes][n5][n10];
    if (ans != -1) return ans;
    ans = cokes * 8; // buy all by 1 val coin (worst case)
    if (n5 == 0 && n10 == 0) return ans;
    if (n10 > 0) ans = min(ans, dp(cokes - 1, n1 + 2, n5, n10 - 1) + 1); // 10 -> 1 1
    if (n10 > 0 && n1 >= 3) ans = min(ans, dp(cokes - 1, n1 - 3, n5 + 1, n10 - 1) + 4); // 10 1 1 1 -> 5
    if (n5 > 0 && n1 >= 3) ans = min(ans, dp(cokes - 1, n1 - 3, n5 - 1, n10) + 4); // 5 1 1 1 -> 0
    if (n5 > 1) ans = min(ans, dp(cokes - 1, n1 + 2, n5 - 2, n10) + 2); // 5 5 -> 1 1
    return ans;
}

// just follow clue to drop n1... weird that it's marked easy on UVA and hard on kattis

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, n1, n5, n10;
        cin >> n >> n1 >> n5 >> n10;
        memset(memo, -1, sizeof(memo));
        cout << dp(n, n1, n5, n10) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
