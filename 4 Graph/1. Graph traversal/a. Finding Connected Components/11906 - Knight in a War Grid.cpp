#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1, WATER = -2
};

int mark[105][105]; // -1 for unvisited, 0 for even 1 for odd
int R, C, M, N, dr[8], dc[8];

void floodfill(int r, int c) {

    // check even or odd 1st
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue; // out of bounds
        if (mark[nr][nc] == WATER) continue; // water
        cnt++;
    }
    if (M == 0 || N == 0 || M == N) cnt /= 2; // should have 4 dir instead of 8. double cnt
    if (cnt % 2 == 0) mark[r][c] = 0;
    else mark[r][c] = 1;

    // flood neighbours
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue; // out of bounds
        if (mark[nr][nc] != UNVISITED) continue; // water or checked earlier
        floodfill(nr, nc);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        cin >> R >> C >> M >> N;
        memset(mark, UNVISITED, sizeof mark);
        int W;
        cin >> W;
        for (int i = 0; i < W; i++) {
            int r, c;
            cin >> r >> c;
            mark[r][c] = WATER;
        }
//        dr = {M, M, -M, -M, N, N, -N, -N};
//        dc = {N, -N, N, -N, M, -M, M, -M};
        dr[0] = dr[1] = M;
        dr[2] = dr[3] = -M;
        dr[4] = dr[5] = N;
        dr[6] = dr[7] = -N;
        dc[0] = dc[2] = N;
        dc[1] = dc[3] = -N;
        dc[4] = dc[6] = M;
        dc[5] = dc[7] = -M;

        int even = 0, odd = 0;
        floodfill(0, 0);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; ++j) {
                if (mark[i][j] == 0) even++;
                else if (mark[i][j] == 1) odd++;
                else continue; // visited (water) or unvisited (didn't reach from (0,0))
            }
        }
        cout << "Case " << cases << ": " << even << " " << odd << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

