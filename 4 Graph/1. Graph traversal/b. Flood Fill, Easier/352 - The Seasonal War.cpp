// Wetlands of Florida
// classic DFS flood fill

#include <bits/stdc++.h>
using namespace std;

char line[30], grid[30][30];
int R, C, RC;

int dr[] = { 1, 1, 0,-1,-1,-1, 0, 1};            // the order is:
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1};            // S/SE/E/NE/N/NW/W/SW

void floodfill(int r, int c) {  // returns the size of CC
    if ((r < 0) || (r >= R) || (c < 0) || (c >= C)) return; // outside grid
    if (grid[r][c] == '0') return;                // does not have color c1
    grid[r][c] = '0';                               // to avoid cycling
    for (int d = 0; d < 8; ++d) floodfill(r+dr[d], c+dc[d]);
}

// inside int main()
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int tc = 1;
    while (cin >> RC) {
        cin.ignore();
        R = C = RC;
        for (int i = 0; i < R; ++i) {
            cin.getline(line, 30);
            for (int j = 0; j < C; ++j)
                grid[i][j] = line[j];
        }
        int ans = 0;
        for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j)
            if (grid[i][j] == '1') { ++ans; floodfill(i, j); }
        cout << "Image number " << tc++ << " contains " << ans << " war eagles.\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}