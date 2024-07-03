#include <bits/stdc++.h>

using namespace std;

char line[150], grid[150][150];
int R, C, size;
char landChar, waterChar;

int dr[] = {1, 0, -1, 0,};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c) {  // returns the size of CC
    // can continue past boundaries left and right
    if (c < 0) c = C - 1;
    if (c >= C) c = 0;
    if (r < 0 || r >= R) return; // cannot north pole to south pole

    if (grid[r][c] == waterChar) return;                // does not have color c1
    grid[r][c] = waterChar;                               // to avoid cycling
    size++;
    for (int d = 0; d < 4; ++d) floodfill(r + dr[d], c + dc[d]);
}

// inside int main()
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (cin >> R >> C) {
        cin.ignore();
        for (int i = 0; i < R; ++i) {
            cin.getline(line, 150);
            for (int j = 0; j < C; ++j)
                grid[i][j] = line[j];
        }

        int X, Y;
        cin >> X >> Y;
        landChar = grid[X][Y]; // he starts on land
        waterChar = landChar;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] != landChar) {
                    waterChar = grid[i][j];
                    break;
                }
            }
        }
        if (waterChar == landChar) {
            cout << 0 << endl;
            continue;
        }
        floodfill(X, Y); // flood original island since he want conquer others

        int maxSize = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (grid[i][j] == landChar) {
                    size = 0;
                    floodfill(i, j);
                    maxSize = max(maxSize, size);
                }
        cout << maxSize << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}