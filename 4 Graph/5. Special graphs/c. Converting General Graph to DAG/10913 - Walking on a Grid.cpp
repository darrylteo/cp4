#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int memo[80][80][6][3];
int grid[80][80], visited[80][80][6][3];

int n, k;

// need last variable to see which move u got here by. if got here by left, we can't use the ans if got here by down/right
int dfs(int row, int col, int negativeCnt, int lastMove) {
    int &ans = memo[row][col][negativeCnt][lastMove];
    if (visited[row][col][negativeCnt][lastMove]) return ans;
    visited[row][col][negativeCnt][lastMove] = 1;
    ans = -1e9;
    if (grid[row][col] < 0) negativeCnt++;
    if (negativeCnt > k) return ans;
    if (row == n - 1 && col == n - 1) return ans = grid[row][col];
    if (lastMove != 1 && col - 1 >= 0) {
        int tmp = dfs(row, col - 1, negativeCnt, 2);
        if (tmp != -1e9) ans = max(ans, tmp + grid[row][col]);
    }
    if (lastMove != 2 && col + 1 < n) {
        int tmp = dfs(row, col + 1, negativeCnt, 1);
        if (tmp != -1e9) ans = max(ans, tmp + grid[row][col]);
    }
    if (row + 1 < n) {
        int tmp = dfs(row + 1, col, negativeCnt, 0);
        if (tmp != -1e9) ans = max(ans, tmp + grid[row][col]);
    }
    return ans;
}

// had trouble with this qn... dp is hard for me
// sort of a DAG since if u go right, you can only go right or down. if go left, only left or down. this way, won't revisit same place

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (cin >> n >> k, n) {
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        cout << "Case " << cases++ << ": ";
        int anz = dfs(0, 0, 0, 0);
        if (anz == -1e9) cout << "impossible\n";
        else cout << anz << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

