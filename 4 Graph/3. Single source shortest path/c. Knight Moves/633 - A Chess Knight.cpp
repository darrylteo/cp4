#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int drK[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dcK[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int drB[] = {2, 2, -2, -2};
const int dcB[] = {2, -2, 2, -2};

int grid[50][50], N, sr, sc, tr, tc;
// r, c, nexttype. nexttype = 0: any move ok.
//  nexttype = 1: bishop or T, nexttype = 2: knight or T, nexttype = 3: knight or bishop
queue<iii> q;

void moveKnight(int r, int c) {
    for (int i = 0; i < 8; i++) {
        int nr = r + drK[i], nc = c + dcK[i];
        if (nr > 0 && nr <= 2 * N && nc > 0 && nc <= 2 * N && (grid[nr][nc] == -1 || grid[nr][nc] == grid[r][c] + 1)) {
            grid[nr][nc] = grid[r][c] + 1;
            q.emplace(nr, nc, 1);
        }
    }
}

void moveBishop(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + drB[i], nc = c + dcB[i];
        if (nr > 0 && nr <= 2 * N && nc > 0 && nc <= 2 * N && (grid[nr][nc] == -1 || grid[nr][nc] == grid[r][c] + 1)) {
            grid[nr][nc] = grid[r][c] + 1;
            q.emplace(nr, nc, 2);
        }
    }
}

void moveT(int r, int c) {
    int nr, nc;
    // reflect in x axis. recall board is 2N x 2N
    nr = 2 * N - r + 1;
    nc = c;
    if (nr > 0 && nr <= 2 * N && nc > 0 && nc <= 2 * N && (grid[nr][nc] == -1 || grid[nr][nc] == grid[r][c] + 1)) {
        grid[nr][nc] = grid[r][c] + 1;
        q.emplace(nr, nc, 3);
    }
    // reflect in y axis
    nr = r;
    nc = 2 * N - c + 1;
    if (nr > 0 && nr <= 2 * N && nc > 0 && nc <= 2 * N && (grid[nr][nc] == -1 || grid[nr][nc] == grid[r][c] + 1)) {
        grid[nr][nc] = grid[r][c] + 1;
        q.emplace(nr, nc, 3);
    }
}

// maybe the way i coded it ended up causing a trick to myself.
// need extra check of || grid[nr][nc] == grid[r][c] + 1 to mark that i could come here by another move with same number of steps
// might be better to mark grid with pair<int, int> to say <step, what moves are allowed from here>.it could be all 3 moves if we visited this with 2 diff moves. 
// should be faster, but testcases are weak compared to udebug so still got 0.000s.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> N >> sr >> sc >> tr >> tc, N) {
        memset(grid, -1, sizeof grid); // let's just do 1 based here
        int badR, badC;
        while (cin >> badR >> badC, badR) {
            grid[badR][badC] = -2; // don't step here
        }

        while (!q.empty()) q.pop();
        q.emplace(sr, sc, 0);
        grid[sr][sc] = 0;
        while (!q.empty()) {
            auto [r, c, type] = q.front();
            q.pop();
            if (r == tr && c == tc) break;
            if (type == 0) {
                moveKnight(r, c);
                moveBishop(r, c);
                moveT(r, c);
            } else if (type == 1) {
                moveBishop(r, c);
                moveT(r, c);
            } else if (type == 2) {
                moveKnight(r, c);
                moveT(r, c);
            } else {
                moveKnight(r, c);
                moveBishop(r, c);
            }
        }
        if (grid[tr][tc] < 0) cout << "Solution doesn't exist\n";
        else cout << "Result : " << grid[tr][tc] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}