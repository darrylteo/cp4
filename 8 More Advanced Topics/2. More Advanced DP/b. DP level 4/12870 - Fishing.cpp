#include <bits/stdc++.h>

using namespace std;

int memo[105][105][105][2]; // i, j, k, {FISH, NOURISH}
int grid[105][105], n, m;

inline int dp(int i, int j, int k, int type) {
    if (k == 0) return 0;
    if (i >= n || j >= m) return (type ? 1e9 : -1e9); // invalidate the current step
    int &ret = memo[i][j][k][type];
    if (ret != -1) return ret;

    if (type) ret = 1e9;
    else ret = 0;

    if (type) {
        ret = min(ret, dp(i, j + 1, k, type)); // skip
        ret = min(ret, dp(i + 1, j, k, type)); // skip
        ret = min(ret, dp(i + 1, j + 1, k - 1, type) + grid[i][j]); // take
    } else {
        ret = max(ret, dp(i, j + 1, k, type));
        ret = max(ret, dp(i + 1, j, k, type));
        ret = max(ret, dp(i + 1, j + 1, k - 1, type) + grid[i][j]);
    }
    dp(i, j, k-1, type);
    return ret;
}

// ref: https://blog.csdn.net/metaphysis/article/details/131341923

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        memset(memo, -1, sizeof(memo));
        int best = 0;
        int kk = min(n, m)/2; // longest diagonal for nourish
        dp(0, 0, kk, 0);
        dp(0, 0, 2*kk, 1);
        for (int k = 0; k <= kk; ++k) {
            best = max(best, memo[0][0][k][0] - memo[0][0][2*k][1]);
        }
        cout << best << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}



