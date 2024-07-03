#include <bits/stdc++.h>

using namespace std;

// ref: https://github.com/isanchez-aguilar/UVa-Solutions/blob/master/1103%20-%20Ancient%20Messages.cpp
// 200 50 cases in udebug recursion depth limit exceeded

const int dr4[] = {0, 0, 1, -1};
const int dc4[] = {1, -1, 0, 0};
const int dr8[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dc8[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m, grid[410][410];

inline void floodfill(int r, int c, int newVal, int oldVal) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (grid[r][c] != oldVal) return;
    grid[r][c] = newVal;
    for (int d = 0; d < 4; d++) floodfill(r + dr4[d], c + dc4[d], newVal, oldVal);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 0;
    int holes[210];
    char symbols[2000];
    char matrix[401][51]; // initial matrix

    while (cin >> n >> m, n) {
        memset(grid, 0, sizeof grid);
        memset(holes, 0, sizeof holes);
        memset(symbols, 0, sizeof symbols);

        for (int i = 0; i < n; i++) cin >> matrix[i];
        // convert to binary
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val;
                if (matrix[i][j] >= '0' && matrix[i][j] <= '9') val = matrix[i][j] - '0';
                else val = matrix[i][j] - 'a' + 10;
                for (int k = 0; k < 4; ++k) {
                    grid[i][j * 4 + k] = (val >> (3 - k)) & 1;
                }
            }
        }
        m = m * 4;
        // debug print
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 cout << grid[i][j];
//             }
//                cout << endl;
//         }
        // remove outer white space (check along border)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 0) floodfill(i, j, -1, 0);
                }
            }
        }
        // check until u bump into 1 (color the outline with id)
        // within this outline, check for holes and put id into holes while keeping track of numHoles
        int id = 2; // start from id 2 since -1 0 1 are already used
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    floodfill(i, j, id, 1);
                    id++; // done filling this outline
                } else if (grid[i][j] == 0) {
                    holes[grid[i - 1][j]]++; // get the id from outline
                    floodfill(i, j, grid[i - 1][j], 0); // fill the hole with the id of outline
                }
            }
        }

        // get symbols
        for (int i = 2; i < id; ++i) {
            if (holes[i] == 0) symbols[i] = 'W';
            else if (holes[i] == 1) symbols[i] = 'A';
            else if (holes[i] == 2) symbols[i] = 'K';
            else if (holes[i] == 3) symbols[i] = 'J';
            else if (holes[i] == 4) symbols[i] = 'S';
            else if (holes[i] == 5) symbols[i] = 'D';
        }

        // sort symbols
        sort(symbols + 2, symbols + id);
        cout << "Case " << ++tc << ": ";
        for (int i = 2; i < id; ++i) {
            cout << symbols[i];
        }
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
