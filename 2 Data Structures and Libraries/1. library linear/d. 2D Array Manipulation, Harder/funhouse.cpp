#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int W, L, caseCnt = 1;
    while (cin >> W >> L, W) {
        cout << "HOUSE " << caseCnt++ << endl;

        vector<vector<char>> grid(L, vector<char>(W));
        for (int i = 0; i < L; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < W; ++j) {
                grid[i][j] = s[j];
            }
        }

        // right = 0, down = 1, left = 2, up = 3
        // x is row number, y is column (kinda opposite)
        int dir = 0, x = 0, y = 0;
        // get start point
        for (int i = 0; i < L; ++i) {
            if (grid[i][0] == '*') {
                x = i;
                y = 0;
                dir = 0;
                break;
            }
        }
        for (int i = 0; i < W; ++i) {
            if (grid[0][i] == '*') {
                x = 0;
                y = i;
                dir = 1;
                break;
            }
        }
        for (int i = 0; i < L; ++i) {
            if (grid[i][W - 1] == '*') {
                x = i;
                y = W - 1;
                dir = 2;
                break;
            }
        }
        for (int i = 0; i < W; ++i) {
            if (grid[L - 1][i] == '*') {
                x = L - 1;
                y = i;
                dir = 3;
                break;
            }
        }

        // dir, x, y are global
        while (true) {
            // found exit
            if (grid[x][y] == 'x') {
                grid[x][y] = '&';
                break;
            }

            // move
            if (dir == 0) ++y;
            else if (dir == 1) ++x;
            else if (dir == 2) --y;
            else if (dir == 3) --x;


            // turn
            if (grid[x][y] == '/') {
                if (dir == 0) dir = 3;
                else if (dir == 1) dir = 2;
                else if (dir == 2) dir = 1;
                else if (dir == 3) dir = 0;
            } else if (grid[x][y] == '\\') {
                if (dir == 0) dir = 1;
                else if (dir == 1) dir = 0;
                else if (dir == 2) dir = 3;
                else if (dir == 3) dir = 2;
            }
        }

        // print
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < W; ++j) {
                cout << grid[i][j];
            }
            cout << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
