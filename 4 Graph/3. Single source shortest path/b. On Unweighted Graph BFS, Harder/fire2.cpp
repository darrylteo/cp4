#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int r, c;
        cin >> c >> r;
        vector<string> grid(r);
        for (int i = 0; i < r; i++) {
            cin >> grid[i];
        }
        queue<ii> qFire[2], qHuman[2]; // alternate queues at each depth (timestep)
        vector<vector<int>> fireDist(r, vector<int>(c, -1));
        vector<vector<int>> humanDist(r, vector<int>(c, -1));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '*') {
                    qFire[0].emplace(i, j);
                    fireDist[i][j] = 0;
                } else if (grid[i][j] == '@') {
                    qHuman[0].emplace(i, j);
                    humanDist[i][j] = 0;
                }
            }
        }
        int qFireIdx = 0, qHumanIdx = 0;
        while (!qFire[qFireIdx].empty() || !qHuman[qHumanIdx].empty()) {
            while (!qFire[qFireIdx].empty()) {
                ii u = qFire[qFireIdx].front();
                qFire[qFireIdx].pop();
                for (int i = 0; i < 4; i++) {
                    int nr = u.first + dr[i];
                    int nc = u.second + dc[i];
                    if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] != '#' && fireDist[nr][nc] == -1) {
                        fireDist[nr][nc] = fireDist[u.first][u.second] + 1;
                        qFire[qFireIdx ^ 1].emplace(nr, nc); // put new fire cells in the next queue (next timestep)
                    }
                }
            }
            qFireIdx ^= 1;
            while (!qHuman[qHumanIdx].empty()) {
                ii u = qHuman[qHumanIdx].front();
                qHuman[qHumanIdx].pop();
                for (int i = 0; i < 4; i++) {
                    int nr = u.first + dr[i];
                    int nc = u.second + dc[i];
                    if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                        cout << humanDist[u.first][u.second] + 1 << endl;
                        goto done;
                    }
                    if (grid[nr][nc] != '#' && humanDist[nr][nc] == -1 && fireDist[nr][nc] == -1) {
                        humanDist[nr][nc] = humanDist[u.first][u.second] + 1;
                        qHuman[qHumanIdx ^ 1].emplace(nr, nc);
                    }
                }
            }
            qHumanIdx ^= 1;
        }
        cout << "IMPOSSIBLE" << endl;
        done:;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}