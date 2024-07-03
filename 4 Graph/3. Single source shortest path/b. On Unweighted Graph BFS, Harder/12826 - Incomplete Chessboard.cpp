#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dr8[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r1, c1, r2, c2, r3, c3, cases = 1;
    int grid[8][8];
    while (cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3) {
        r1--, c1--, r2--, c2--, r3--, c3--;
        memset(grid, -1, sizeof grid);
        queue<ii> q;
        q.emplace(r1, c1);
        grid[r1][c1] = 0;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            if (u.first == r2 && u.second == c2) break;
            for (int i = 0; i < 8; i++) {
                int r = u.first + dr8[i];
                int c = u.second + dc8[i];
                if (r >= 0 && r < 8 && c >= 0 && c < 8 && grid[r][c] == -1) {
                    if (r == r3 && c == c3) continue; // skip the forbidden cell
                    grid[r][c] = grid[u.first][u.second] + 1;
                    q.emplace(r, c);
                }
            }
        }
        cout << "Case " << cases++ << ": " << grid[r2][c2] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}