#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, T, memo[55][5005], memo2[55][5005], grid[55][55];

inline int dp(int u, int t) { // curr room, steps left
    if (t == T) return 0;
    int &ans = memo[u][t];
    if (ans != -1) return ans;
    ans = 0;
    for (int v = 0; v < N; v++) {
        ans = max(ans, dp(v, t + 1) + grid[u][v]);
    }
    return ans;
}

inline int dp2(int u, int t) { // curr room, steps left
    if (t == T) return 0;
    int &ans = memo2[u][t];
    if (ans != -1) return ans;
    ans = 1e9;
    for (int v = 0; v < N; v++) {
        ans = min(ans, dp2(v, t + 1) + grid[u][v]);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> N, N) {
        memset(memo, -1, sizeof memo);
        memset(memo2, -1, sizeof memo2);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
            }
        }
        cin >> T;
        cout << dp(0, 0) << " " << dp2(0, 0) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

