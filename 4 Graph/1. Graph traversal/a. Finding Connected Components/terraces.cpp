#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1, VISITED = -2
};

int visited[505][505], grid[505][505];
int R, C, valid, sizeCC;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void floodfill(int r, int c, int c1) {  // returns the size of CC
    visited[r][c] = VISITED;
    sizeCC++;

    for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= C || nc < 0 || nc >= R) continue;
        if (grid[nr][nc] < c1) valid = 0;
        if (visited[nr][nc] == UNVISITED && grid[nr][nc] == c1) {
            floodfill(nr, nc, c1);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> R >> C;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < R; j++) {
            cin >> grid[i][j];
        }
    }
    memset(visited, UNVISITED, sizeof visited);
    int ans = 0;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < R; j++) {
            if (visited[i][j] == UNVISITED) {
                valid = 1;
                sizeCC = 0;
                floodfill(i, j, grid[i][j]);
                if (valid) {
                    ans += sizeCC;
                }
            }
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}