#include <bits/stdc++.h>

using namespace std;

const int dr4[] = {0, 0, 1, -1};
const int dc4[] = {1, -1, 0, 0};
const int dr8[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dc8[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m;
char grid[2000][2000];

inline void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (grid[r][c] == 'W') return; // cover both 'L' and 'C'
    grid[r][c] = 'W';
    for (int d = 0; d < 4; d++) floodfill(r + dr4[d], c + dc4[d]);
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
            grid[r][c] = s[c];
        }
    }

    // find land count
    int ans = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) if (grid[r][c] == 'L') {
            ans++;
            floodfill(r, c);
        }
    }

    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



