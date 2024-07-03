#include <bits/stdc++.h>

using namespace std;

// N, E, S, W ... clockwise
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int grid[105][105];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S;
    while (cin >> N >> M >> S, N) {
        int x, y, dir;
        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < M; ++j) {
                if (s[j] == '.') continue; // leave as 0
                if (s[j] == '*') grid[i][j] = 1; // 1 for sticker
                if (s[j] == '#') grid[i][j] = 2; // 2 for wall
                if (s[j] == 'N') {
                    x = i;
                    y = j;
                    dir = 0;
                }
                if (s[j] == 'S') {
                    x = i;
                    y = j;
                    dir = 2;
                }
                if (s[j] == 'L') {
                    x = i;
                    y = j;
                    dir = 1;
                }
                if (s[j] == 'O') {
                    x = i;
                    y = j;
                    dir = 3;
                }
            }
        }

        string cmd;
        cin >> cmd;
        int ans = 0;
        for (int j = 0; j < S; ++j) {
            if (cmd[j] == 'D') {
                dir = (dir + 1) % 4;
            } else if (cmd[j] == 'E') {
                dir = (dir + 3) % 4;
            } else {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M || grid[nx][ny] == 2) continue;
                if (grid[nx][ny] == 1) {
                    ans++;
                    grid[nx][ny] = 0;
                }
                x = nx;
                y = ny;
            }
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
