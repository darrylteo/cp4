#include <bits/stdc++.h>

using namespace std;

char line[150], grid[150][150];
int R, C, ans;

int dr[] = {1, 0, -1, 0,};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c) {  // returns the size of CC
    if ((r < 0) || (r >= R) || (c < 0) || (c >= C)) return; // outside grid
    if (grid[r][c] == 'T' || grid[r][c] == '#') return;                // does not have color c1
    if (grid[r][c] == 'G') ++ans;
    grid[r][c] = '#';                               // to avoid cycling
    int nearTrap = 0;
    for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d], nc = c + dc[d];
        if ((nr < 0) || (nr >= R) || (nc < 0) || (nc >= C)) continue;
        if (grid[nr][nc] == 'T') nearTrap++;
    }
    if (nearTrap > 0) return; // don't explore further
    for (int d = 0; d < 4; ++d) floodfill(r + dr[d], c + dc[d]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> C >> R;
    cin.ignore();
    for (int i = 0; i < R; ++i) {
        cin.getline(line, 150);
        for (int j = 0; j < C; ++j)
            grid[i][j] = line[j];
    }
    ans = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (grid[i][j] == 'P') {
                floodfill(i, j);
            }
    cout << ans << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}