#include <bits/stdc++.h>

using namespace std;

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};

// start at midpoint and bfs to fill grid, deleting walls along path
// e.g. from (0,0) to (0,1). on grid would be (1,1) and (1,3). so delete wall at (1,2)
// e.g. from (0,0) to (1,0). on grid would be (1,1) and (2,1). so delete wall at (1,1)
// corner cases are when have 2 centers. normally go right will go 2nd center, but when (R % 2 == 0 && C % 2 == 1) must go up first

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vector<string> grid(R + 1, string(2 * C + 1, '_'));
    for (int i = 0; i < 2 * C + 1; i++) { // start with fully blocked walls
        if (i % 2 == 0) grid[0][i] = ' ';
        for (int j = 1; j < R + 1; j++) {
            if (i % 2 == 0) grid[j][i] = '|';
        }
    }
    grid[0].pop_back(); // don't leave a space else WA
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    queue<pair<int, int>> q;
    int rr = R / 2, cc = C / 2;
    q.emplace(rr, cc);
    vis[rr][cc] = true;
    if (R % 2 == 0 && C % 2 == 1) { // go up first.
        grid[rr][2 * cc + 1] = ' ';
        q.emplace(rr - 1, cc);
        vis[rr - 1][cc] = true;
    }
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dirr[k], nc = c + dirc[k];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.emplace(nr, nc);
                if (k == 0) grid[r + 1][2 * c + 2] = ' '; // go right
                else if (k == 1) grid[r + 1][2 * c] = ' '; // go left
                else if (k == 2) grid[r + 1][2 * c + 1] = ' '; // go down
                else grid[r][2 * c + 1] = ' '; // go up
            }
        }
    }
    for (int i = 0; i < R + 1; i++) cout << grid[i] << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
