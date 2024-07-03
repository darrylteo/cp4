#include <bits/stdc++.h>

using namespace std;

const int dr4[] = {0, 0, 1, -1};
const int dc4[] = {1, -1, 0, 0};
const int dr8[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dc8[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m;
int grid[1005][1005];

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

    cin >> n >> m;
    for (int r = 0; r < n; r++) {
        string s;
        cin >> s;
        for (int c = 0; c < m; c++) {
            grid[r][c] = s[c] - '0';
        }
    }
    int idBin = -1, idDec = 2;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 0) floodfill(r, c, idBin--, 0);
            if (grid[r][c] == 1) floodfill(r, c, idDec++, 1);
        }
    }

    int x;
    cin >> x;
    while (x--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        if (grid[r1][c1] == grid[r2][c2]) {
            if (grid[r1][c1] < 0) cout << "binary\n";
            else cout << "decimal\n";

        } else cout << "neither\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
