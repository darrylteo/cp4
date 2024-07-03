#include <bits/stdc++.h>

using namespace std;

char grid[4][4];
int xAns = -1, yAns = -1;

inline int xWin() {
    // check rows
    for (int i = 0; i < 4; ++i) {
        if (grid[i][0] == 'x' && grid[i][1] == 'x' && grid[i][2] == 'x' && grid[i][3] == 'x') return 1;
    }

    // check columns
    for (int i = 0; i < 4; ++i) {
        if (grid[0][i] == 'x' && grid[1][i] == 'x' && grid[2][i] == 'x' && grid[3][i] == 'x') return 1;
    }

    // check diagonals
    if (grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x' && grid[3][3] == 'x') return 1;
    if (grid[0][3] == 'x' && grid[1][2] == 'x' && grid[2][1] == 'x' && grid[3][0] == 'x') return 1;

    return 0;
}

inline int oWin() {
    // check rows
    for (int i = 0; i < 4; ++i) {
        if (grid[i][0] == 'o' && grid[i][1] == 'o' && grid[i][2] == 'o' && grid[i][3] == 'o') return 1;
    }

    // check columns
    for (int i = 0; i < 4; ++i) {
        if (grid[0][i] == 'o' && grid[1][i] == 'o' && grid[2][i] == 'o' && grid[3][i] == 'o') return 1;
    }

    // check diagonals
    if (grid[0][0] == 'o' && grid[1][1] == 'o' && grid[2][2] == 'o' && grid[3][3] == 'o') return 1;
    if (grid[0][3] == 'o' && grid[1][2] == 'o' && grid[2][1] == 'o' && grid[3][0] == 'o') return 1;

    return 0;
}

inline int dp() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == '.') {
                grid[i][j] = 'x';
                if (xWin()) { // sure xWin
                    xAns = i;
                    yAns = j;
                    grid[i][j] = '.';
                    return 1;
                } else { // find a place to put o. if all places of o still let x win, then x xWin
                    int found = 0;
                    for (int k = 0; k < 4; ++k) {
                        for (int l = 0; l < 4; ++l) {
                            if (grid[k][l] == '.') {
                                grid[k][l] = 'o';
                                if (oWin() || !dp()) { // oh no x loses
                                    found = 1;
                                    grid[k][l] = '.';
                                    break;
                                }
                                grid[k][l] = '.';
                            }
                        }
                        if (found) break;
                    }
                    if (!found) {
                        xAns = i;
                        yAns = j;
                        grid[i][j] = '.';
                        return 1;
                    }
                }
                grid[i][j] = '.';
            }
        }
    }
    return 0;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char c;
    while (cin >> c, c != '$') {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> grid[i][j];
            }
        }
        xAns = -1;
        yAns = -1;
        if (!dp()) cout << "#####\n";
        else cout << "(" << xAns << "," << yAns << ")\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

