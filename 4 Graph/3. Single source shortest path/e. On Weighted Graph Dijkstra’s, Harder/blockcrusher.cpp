#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int dr8[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    while (cin >> R >> C, R) {
        vector<vector<int>> grid(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < C; j++) {
                grid[i][j] = s[j] - '0';
            }
        }

        set<iii> pq; // row, col, dist
        vector<vii> parent(R, vii(C, {-1, -1}));
        vector<vector<int>> dist(R, vector<int>(C, 1e9));
        // first row 0 dist
        for (int i = 0; i < C; i++) {
            dist[0][i] = grid[0][i];
            pq.insert({0, i, 0});
        }

        while (!pq.empty()) {
            auto [r, c, d] = *pq.begin();
            pq.erase(pq.begin());
            for (int i = 0; i < 8; i++) {
                int nr = r + dr8[i];
                int nc = c + dc8[i];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    if (dist[nr][nc] > dist[r][c] + grid[nr][nc]) {
                        pq.erase({nr, nc, dist[nr][nc]});
                        dist[nr][nc] = dist[r][c] + grid[nr][nc];
                        pq.insert({nr, nc, dist[nr][nc]});
                        parent[nr][nc] = {r, c};
                    }
                }
            }
        }

        // find last row min dist
        int least = 1e9, leastIdx = -1;
        for (int i = 0; i < C; i++) {
            if (dist[R - 1][i] < least) {
                least = dist[R - 1][i];
                leastIdx = i;
            }
        }
        // trace back parents and mark on grid
        int r = R - 1, c = leastIdx;
        while (r != -1 && c != -1) {
            grid[r][c] = -1;
            auto [pr, pc] = parent[r][c];
            r = pr;
            c = pc;
        }
        // print
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == -1) {
                    cout << " ";
                } else {
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}