#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but shortcuts are useful in competitive programming

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1}; // S, E, N, W

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vector<vector<int>> gridJump(R, vector<int>(C, 0));
    vector<vector<int>> grid(R, vector<int>(C, 1e9));
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            gridJump[i][j] = s[j] - '0';
        }
    }
    queue<ii> q; // (row, column)
    q.emplace(0, 0);
    grid[0][0] = 0;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int mult = gridJump[u.first][u.second];
            int r = u.first + dr[i] * mult;
            int c = u.second + dc[i] * mult;
            if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] == 1e9) {
                grid[r][c] = grid[u.first][u.second] + 1;
                q.emplace(r, c);
            }
        }
    }
    if (grid[R - 1][C - 1] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << grid[R - 1][C - 1] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}