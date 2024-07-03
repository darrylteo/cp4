#include <bits/stdc++.h>

using namespace std;

char line[20], grid[10][10];
int R, C, cnt, blackNeighbor, whiteNeighbor;

int dr[] = {1, 0, -1, 0,};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;

    if (grid[r][c] == '#') return;
    if (grid[r][c] == 'X') {
        blackNeighbor++;
        return;
    }
    if (grid[r][c] == 'O') {
        whiteNeighbor++;
        return;
    }

    if (grid[r][c] == '.') {
        grid[r][c] = '#';
        cnt++;
    }

    for (int d = 0; d < 4; ++d) {
        floodfill(r + dr[d], c + dc[d]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    R = C = 9;
    cin.ignore();
    while (T--) {
        int white = 0, black = 0;
        for (int i = 0; i < R; ++i) {
            cin.getline(line, 20);
            for (int j = 0; j < C; ++j) {
                grid[i][j] = line[j];
                if (grid[i][j] == 'O') {
                    white++;
                } else if (grid[i][j] == 'X') {
                    black++;
                }
            }
        }

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '.') {
                    cnt = 0;
                    blackNeighbor = whiteNeighbor = 0;
                    floodfill(i, j);
                    if (blackNeighbor > 0 && whiteNeighbor == 0) {
                        black += cnt;
                    } else if (whiteNeighbor > 0 && blackNeighbor == 0) {
                        white += cnt;
                    }
                }
            }
        }

        cout << "Black " << black << " White " << white << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}