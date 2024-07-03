#include <bits/stdc++.h>

using namespace std;

// NESW
vector<int> dirr = {-1, 0, 1, 0};
vector<int> dirc = {0, 1, 0, -1};
int dist[1005][1005][4][2]; // x, y, dir, steps in dir (0 is 1 step, 1 is 2 steps. cannot continue dir if 2 steps)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];
        int sx, sy, tx, ty;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'R') {
                    sx = i;
                    sy = j;
                }
                if (grid[i][j] == 'D') {
                    tx = i;
                    ty = j;
                }
            }
        }
        memset(dist, -1, sizeof(dist));
        int found = 0;
        queue<tuple<int, int, int, int>> q;
        q.emplace(sx, sy, 0, 0);
        q.emplace(sx, sy, 1, 0);
        q.emplace(sx, sy, 2, 0);
        q.emplace(sx, sy, 3, 0);
        dist[sx][sy][0][0] = dist[sx][sy][1][0] = dist[sx][sy][2][0] = dist[sx][sy][3][0] = 0;
        while (!q.empty()) {
            auto [x, y, dir, steps] = q.front();
            q.pop();
            if (x == tx && y == ty) {
                found = 1;
                cout << dist[x][y][dir][steps] << endl;
                break;
            }

            if (steps == 0) { // can walk any dir except backwards. if same dir, increase steps.
                for (int i = 0; i < 4; i++) {
                    int nx = x + dirr[i];
                    int ny = y + dirc[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 'B' && dist[nx][ny][i][0] == -1) {
                        if (i == dir) { // same dir, increase steps
                            dist[nx][ny][i][steps + 1] = dist[x][y][dir][steps] + 1;
                            q.emplace(nx, ny, i, steps + 1);
                        } else if (dirr[i] == -dirr[dir] && dirc[i] == -dirc[dir]) {
                            // backwards
                        } else {
                            dist[nx][ny][i][steps] = dist[x][y][dir][steps] + 1;
                            q.emplace(nx, ny, i, steps);
                        }
                    }
                }
            } else if (steps == 1) { // cannot walk same dir or backwards. reset steps since new dir.
                for (int i = 0; i < 4; i++) {
                    int nx = x + dirr[i];
                    int ny = y + dirc[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 'B' && dist[nx][ny][i][0] == -1) {
                        if (dirr[i] == -dirr[dir] && dirc[i] == -dirc[dir] || i == dir) {
                            // backwards or same dir
                        } else {
                            dist[nx][ny][i][0] = dist[x][y][dir][steps] + 1;
                            q.emplace(nx, ny, i, 0);
                        }
                    }
                }
            }
        }
        if (!found) cout << -1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}