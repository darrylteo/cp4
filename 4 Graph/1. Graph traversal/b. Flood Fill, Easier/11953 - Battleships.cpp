#include <bits/stdc++.h>

using namespace std;

char line[105], grid[105][105];
int R, C, RC;

int dr[] = {1, 0, -1, 0,};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c) {
    if ((r < 0) || (r >= R) || (c < 0) || (c >= C)) return; // outside grid
    if (grid[r][c] == '.') return;                // does not have color c1
    grid[r][c] = '.';                               // to avoid cycling
    for (int d = 0; d < 4; ++d) floodfill(r + dr[d], c + dc[d]);
}

// inside int main()
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Case " << cases << ": ";
        cin >> RC;
        cin.ignore();
        R = C = RC;
        for (int i = 0; i < R; ++i) {
            cin.getline(line, 105);
            for (int j = 0; j < C; ++j)
                grid[i][j] = line[j];
        }
        int ans = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (grid[i][j] == 'x') {
                    ++ans;
                    floodfill(i, j);
                }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}