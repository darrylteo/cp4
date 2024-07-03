#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

int memo[100][100], grid[100][100], n, k;

inline int dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) return 0;
    if (memo[r][c] != -1) return memo[r][c];
    int ans = 0;

    // pick the best out of 4 directions
    for (int i = 1; i <= k; i++) {
        if (r + i < n && grid[r + i][c] > grid[r][c])
            ans = max(ans, dfs(r + i, c));
        if (r - i >= 0 && grid[r - i][c] > grid[r][c])
            ans = max(ans, dfs(r - i, c));
        if (c + i < n && grid[r][c + i] > grid[r][c])
            ans = max(ans, dfs(r, c + i));
        if (c - i >= 0 && grid[r][c - i] > grid[r][c])
            ans = max(ans, dfs(r, c - i));
    }

    // pick up best direction + ur current coin
    return memo[r][c] = ans + grid[r][c];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        memset(memo, -1, sizeof(memo));
        cout << dfs(0, 0) << '\n';
        if (T) cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}