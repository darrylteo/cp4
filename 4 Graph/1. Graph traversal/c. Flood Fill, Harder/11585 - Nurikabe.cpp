#include <bits/stdc++.h>

using namespace std;

const int dr4[] = {0, 0, 1, -1};
const int dc4[] = {1, -1, 0, 0};
const int dr8[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dc8[] = {1, -1, 0, 0, 1, -1, 1, -1};

struct point {
    int r, c, val;
};

int n, m, k, solved, cnt, touchEdge;
char grid[110][110];
vector<point> points;

inline void floodfill(int r, int c, int newVal, int oldVal) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (grid[r][c] != oldVal) return;
    grid[r][c] = newVal;
    cnt++;
    for (int d = 0; d < 4; d++) floodfill(r + dr4[d], c + dc4[d], newVal, oldVal);
}

inline void floodfillCorner(int r, int c, int newVal, int oldVal) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (grid[r][c] != oldVal) return;
    grid[r][c] = newVal;
    if (r == 0 || r == n - 1 || c == 0 || c == m - 1) touchEdge = 1;
    for (int d = 0; d < 8; d++) floodfillCorner(r + dr8[d], c + dc8[d], newVal, oldVal);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solved = 1;
        memset(grid, 0, sizeof grid);
        points.clear();
        cin >> n >> m >> k;
        points.resize(k);
        for (int i = 0; i < k; i++) cin >> points[i].r >> points[i].c >> points[i].val;
        for (int i = 0; i < n; ++i) cin >> grid[i];

        // condition 4. no 2x2 square of cells can be all unshaded
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                int cntUnshaded = 0;
                if (grid[i][j] == '.') cntUnshaded++;
                if (grid[i + 1][j] == '.') cntUnshaded++;
                if (grid[i][j + 1] == '.') cntUnshaded++;
                if (grid[i + 1][j + 1] == '.') cntUnshaded++;
                if (!cntUnshaded) {
                    solved = 0;
                    break;
                }
            }
        }
        if (!solved) {
            cout << "not solved\n";
            continue;
        }

        // condition 1. shaded must all be connected. grid is modified to '@' for shaded
        int shadedCC = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m ; ++j) {
                if (grid[i][j] == '.') continue;
                if (grid[i][j] == '#') {
                    shadedCC++;
                    floodfill(i, j, '@', '#');
                }
            }
        }
        if (shadedCC > 1) {
            cout << "not solved\n";
            continue;
        }

        // condition 2. each clue must be equal to the number of shaded cells connected to it
        // grid is modified to '!' for unshaded
        for (int i = 0; i < k; ++i) {
            cnt = 0;
            floodfill(points[i].r, points[i].c, '!', '.');
            if (cnt != points[i].val) {
                solved = 0;
                break;
            }
        }
        // should have no '.' left
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m ; ++j) {
                if (grid[i][j] == '.') {
                    solved = 0;
                    break;
                }
            }
        }
        if (!solved) {
            cout << "not solved\n";
            continue;
        }

        // condition 3. all unshaded cells must be connected to at least one edge (check 8 dir since corner touch is ok)
        // update unshaded to 'U'. if it is U, skip this clue since it was flooded from another clue
        for (int i = 0; i < k; ++i) {
            if (grid[points[i].r][points[i].c] == 'U') continue;
            touchEdge = 0;
            floodfillCorner(points[i].r, points[i].c, 'U', '!');
            if (!touchEdge) {
                solved = 0;
                break;
            }
        }
        if (!solved) {
            cout << "not solved\n";
            continue;
        }

        // congrats
        cout << "solved\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
