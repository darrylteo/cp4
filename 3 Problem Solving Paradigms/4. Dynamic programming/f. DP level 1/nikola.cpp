#include <bits/stdc++.h>

using namespace std;

// not sure if able to bottom up here since next state depends on some future states (the jumping backwards)
// going for top down again :S

int costs[1005], dp[1005][1005], n;

int solve(int pos, int lastJump) {
    if (pos < 0 || pos >= n) return 1e7; // out of bounds
    if (pos == 0 && lastJump == 0) return 0; // starting pos
    if (lastJump == 0) return 1e7; // can't jump
    int &ans = dp[pos][lastJump];
    if (ans != -1) return ans;
    // min(forward, backward)
    return ans = min(solve(pos - lastJump, lastJump - 1), solve(pos + lastJump, lastJump)) + costs[pos];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = 1e7;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, solve(n - 1, i));
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

