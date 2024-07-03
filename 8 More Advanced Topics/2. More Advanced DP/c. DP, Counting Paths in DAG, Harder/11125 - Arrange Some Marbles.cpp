#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// qn refers to size as in number of marbles in grp.
int memo[8][8][8][8][4][4][4][4]; // remaining for c1 - c4. first c, first sz, curr c, curr sz
int n, marbles[4];

// no need marbles as var since we do backtracking
int dp(int first_c, int first_sz, int c, int sz) {
    if (accumulate(marbles, marbles + n, 0) == 0 && c != first_c && sz != first_sz) {
        return 1; // success. used all with diff color and diff grp size from first.
    }
    int &ans = memo[marbles[0]][marbles[1]][marbles[2]][marbles[3]][first_c][first_sz][c][sz];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < n; ++i) { // try all colors
        for (int j = 1; j <= min(3, marbles[i]); ++j) { // try all group sizes. (can't be more than 3)
            if (c == i || sz == j) continue; // same color or same size as last group
            marbles[i] -= j;
            ans += dp(first_c, first_sz, i, j);
            marbles[i] += j;
        }
    }
    return ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    memset(memo, -1, sizeof(memo));
    while (T--) {
        cin >> n;
        memset(marbles, 0, sizeof(marbles));
        for (int i = 0; i < n; ++i) cin >> marbles[i];

        // cases from udebug... since our algo doesn't catch when there is only 1 group since prev == first.
        int sum = accumulate(marbles, marbles + n, 0);
        int cnt = 0, idx = -1;
        for (int i = 0; i < n; ++i) if (marbles[i] > 0) {
            cnt++;
            idx = i;
        }
        if (sum == 0 || cnt == 1 && marbles[idx] <= 3) {
            cout << 1 << endl;
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= min(3, marbles[i]); ++j) {
                marbles[i] -= j;
                ans += dp(i, j, i, j);
                marbles[i] += j;
            }
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
