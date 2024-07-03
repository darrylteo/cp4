#include <bits/stdc++.h>

using namespace std;

const int dr4[] = {0, 0, 1, -1};
const int dc4[] = {1, -1, 0, 0};
const int dr8[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dc8[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m, touchEdge, cnt;
int grid[2000][2000];

inline void floodfill(int r, int c, int newVal, int oldVal) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (grid[r][c] != oldVal) return;
    grid[r][c] = newVal;
    if (r == 0 || r == n - 1 || c == 0 || c == m - 1) touchEdge = 1;
    for (int d = 0; d < 4; d++) floodfill(r + dr4[d], c + dc4[d], newVal, oldVal);
}

inline void floodfill2(int r, int c, int newVal, int oldVal) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (grid[r][c] != oldVal) return;
    grid[r][c] = newVal;

    // check touch edge of map
    if (r == 0) cnt++;
    if (r == n - 1) cnt++;
    if (c == 0) cnt++;
    if (c == m - 1) cnt++;

    for (int d = 0; d < 4; d++) {
        int nr = r + dr4[d];
        int nc = c + dc4[d];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (grid[nr][nc] == 2) cnt++; // touch edge of land 2
    }

    for (int d = 0; d < 4; d++) floodfill2(r + dr4[d], c + dc4[d], newVal, oldVal);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int r = 0; r < n; r++) {
        string s;
        cin >> s;
        for (int c = 0; c < m; c++) {
            grid[r][c] = s[c] - '0';
        }
    }

    // land = 2, water = 1, island = 3
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 0) {
                // convert land 0 to land 2. if no touch edge is island so change it to 3
                touchEdge = 0;
                floodfill(r, c, 2, 0);
                if (!touchEdge) floodfill(r, c, 3, 2);
            }
        }
    }

    // count shore
    cnt = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 1) floodfill2(r, c, 10, 1); // fill with any number is ok
        }
    }

    cout << cnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



