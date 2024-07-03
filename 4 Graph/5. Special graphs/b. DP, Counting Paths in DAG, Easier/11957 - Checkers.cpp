#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int n;
        cin >> n;
        char grid[n][n];
        ll parentCnt[n][n];
        int visited[n][n];
        int sr = -1, sc = -1;
        for (int i = 0; i < n; i++) cin >> grid[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    sr = i;
                    sc = j;
                }
            }
        }
        if (sr == -1 || sc == -1) { // lame i knew there was a testcase without W since runtime error
            cout << "Case " << cases << ": 0" << endl;
            continue;
        }
        priority_queue<ii> q; // "topsort"
        q.emplace(sr, sc);
        memset(parentCnt, 0, sizeof(parentCnt));
        memset(visited, 0, sizeof(visited));
        parentCnt[sr][sc] = 1;
        visited[sr][sc] = 1;
        while (!q.empty()) {
            ii u = q.top();
            q.pop();
            int r = u.first, c = u.second;
            // 4 possible moves
            if (r - 1 >= 0 && c - 1 >= 0 && grid[r - 1][c - 1] == '.') {
                // upleft
                parentCnt[r - 1][c - 1] += parentCnt[r][c] % 1000007;
                if (!visited[r - 1][c - 1]) {
                    visited[r - 1][c - 1] = 1;
                    q.emplace(r - 1, c - 1);
                }
            } else if (r - 2 >= 0 && c - 2 >= 0 && grid[r - 1][c - 1] == 'B' && grid[r - 2][c - 2] == '.') {
                // upleft and eat black
                parentCnt[r - 2][c - 2] += parentCnt[r][c] % 1000007;
                if (!visited[r - 2][c - 2]) {
                    visited[r - 2][c - 2] = 1;
                    q.emplace(r - 2, c - 2);
                }
            }
            if (r - 1 >= 0 && c + 1 < n && grid[r - 1][c + 1] == '.') {
                // upright
                parentCnt[r - 1][c + 1] += parentCnt[r][c] % 1000007;
                if (!visited[r - 1][c + 1]) {
                    visited[r - 1][c + 1] = 1;
                    q.emplace(r - 1, c + 1);
                }
            } else if (r - 2 >= 0 && c + 2 < n && grid[r - 1][c + 1] == 'B' && grid[r - 2][c + 2] == '.') {
                // upright and eat black
                parentCnt[r - 2][c + 2] += parentCnt[r][c] % 1000007;
                if (!visited[r - 2][c + 2]) {
                    visited[r - 2][c + 2] = 1;
                    q.emplace(r - 2, c + 2);
                }
            }
        }
        // sum ways to get to top row
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += parentCnt[0][i] % 1000007;
        }
        cout << "Case " << cases << ": " << ans % 1000007 << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
