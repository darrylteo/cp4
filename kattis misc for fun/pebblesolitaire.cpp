#include <bits/stdc++.h>

using namespace std;

int memo[1 << 12];

int dp(int mask) {
    if (memo[mask] != -1) return memo[mask];
    int ans = __builtin_popcount(mask);
    for (int i = 0; i < 10; ++i) {
        int tmp = 1 << (i + 2) | 1 << (i + 1) |  1 << i;
        // get only the three bits and shift all the way to the right so only possible vals are 0-7
        int curr = mask & tmp;
        curr >>= i;
        // if curr == 3 (011), eat mid, go left. i.e. become (100)
        // if curr == 6 (110), eat mid, go right. i.e. become (001) can think of it as flipping these 3 bits
        if (curr == 3) {
            int new_mask = mask ^ tmp;
            ans = min(ans, dp(new_mask));
        } else if (curr == 6) {
            int new_mask = mask ^ tmp;
            ans = min(ans, dp(new_mask));
        }
    }
    return memo[mask] = ans;
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
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < 12; ++i) {
            if (s[i] == 'o') mask |= 1 << i;
        }
        memset(memo, -1, sizeof(memo));
        cout << dp(mask) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
