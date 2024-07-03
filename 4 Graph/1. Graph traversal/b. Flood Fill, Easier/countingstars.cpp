#include <bits/stdc++.h>
using namespace std;

char line[150], grid[150][150];
int R, C;

int dr[] = {1, 0, -1, 0,};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c) {  // returns the size of CC
    if ((r < 0) || (r >= R) || (c < 0) || (c >= C)) return; // outside grid
    if (grid[r][c] == '#') return;                // does not have color c1
    grid[r][c] = '#';                               // to avoid cycling
    for (int d = 0; d < 4; ++d) floodfill(r+dr[d], c+dc[d]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int cases = 1;
    while (cin >> R >> C) {
        cin.ignore();
        for (int i = 0; i < R; ++i) {
            cin.getline(line, 150);
            for (int j = 0; j < C; ++j)
                grid[i][j] = line[j];
        }
        int ans = 0;
        for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j)
                if (grid[i][j] == '-') { ++ans; floodfill(i, j); }
        cout << "Case " << cases++ << ": " << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}