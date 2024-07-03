#include <bits/stdc++.h>

using namespace std;

struct trip {
    int time, nibbles;
};

int n, dp[105][105]; // idx, nibbles. stores best time
trip trips[105];

int solve(int idx, int nibbles) {
    if (idx == n) return 0;
    if (nibbles > n) nibbles = n; // so that we don't go out of bounds anyway cannot use so many times. only n trips
    int &ans = dp[idx][nibbles];
    if (ans != -1) return ans;
    if (nibbles > 0) {
        ans = min(solve(idx + 1, nibbles - 1 + trips[idx].nibbles) + trips[idx].time/2, solve(idx + 1, nibbles + trips[idx].nibbles) + trips[idx].time);
    } else {
        ans = solve(idx + 1, trips[idx].nibbles) + trips[idx].time;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> n && n != 0) {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++) {
            cin >> trips[i].time >> trips[i].nibbles;
        }
        cout << solve(0, 0) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


