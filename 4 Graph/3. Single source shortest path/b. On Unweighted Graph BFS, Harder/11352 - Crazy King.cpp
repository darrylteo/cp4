#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dr8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc8[] = {0, 1, 1, 1, 0, -1, -1, -1}; // 8 for king

const int drH[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dcH[] = {-1, 1, -2, 2, -2, 2, -1, 1}; // h for horse

// from qn it appears that horses either stay or do 1 move. just block these squares in 1 pass and then do bfs
// nothing special. just remember to have second graph for copy

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
        cin >> r >> c;
        vector<string> grid(r);
        for (int i = 0; i < r; i++) cin >> grid[i];
        // first pass for blocking. and getting start and end
        int sr, sc, tr, tc;
        vector<string> grid2 = grid;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'Z') {
                    grid2[i][j] = 'Z';
                    for (int k = 0; k < 8; k++) {
                        int nr = i + drH[k];
                        int nc = j + dcH[k];
                        if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == '.') {
                            grid2[nr][nc] = 'Z';
                        }
                    }
                } else if (grid[i][j] == 'A') {
                    sr = i;
                    sc = j;
                } else if (grid[i][j] == 'B') {
                    tr = i;
                    tc = j;
                }
            }
        }
        grid = grid2;

        // 2nd pass bfs
        queue<ii> q;
        q.push({sr, sc});
        vector<vi> dist(r, vi(c, -1));
        dist[sr][sc] = 0;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            if (u.first == tr && u.second == tc) {
                cout << "Minimal possible length of a trip is " << dist[tr][tc] << "\n";
                break;
            }
            for (int i = 0; i < 8; i++) {
                int nr = u.first + dr8[i];
                int nc = u.second + dc8[i];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] != 'Z' && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[u.first][u.second] + 1;
                    q.push({nr, nc});
                }
            }
        }
        if (dist[tr][tc] == -1) cout << "King Peter, you can't go now!" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}