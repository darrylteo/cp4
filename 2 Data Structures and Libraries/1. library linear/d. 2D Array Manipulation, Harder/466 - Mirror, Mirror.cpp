#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<char>> &grid) {
    int n = grid.size();
    vector<vector<char>> temp(n, vector<char>(n));
    // rotate 90 degree
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            temp[i][n - j - 1] = grid[j][i];
        }
    }
    grid = temp;
}

void reflect(vector<vector<char>> &grid) {
    int n = grid.size();
    vector<vector<char>> temp(n, vector<char>(n));
    // reflect
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            temp[j][i] = grid[n - 1 - j][i];
        }
    }
    grid = temp;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, caseCnt = 1;
    while (cin >> n) {
        cout << "Pattern " << caseCnt++ << " was ";
        // get data
        vector<vector<char>> grid1(n, vector<char>(n)), grid2(n, vector<char>(n)); // easy compare equality
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                grid1[i][j] = s[j];
            }
            cin >> s;
            for (int j = 0; j < n; j++) {
                grid2[i][j] = s[j];
            }
        }

        if (grid1 == grid2) {
            cout << "preserved." << endl;
            continue;
        }

        // rotate 90 degree
        rotate(grid1);
        if (grid1 == grid2) {
            cout << "rotated 90 degrees." << endl;
            continue;
        }

        // rotate 180 degree
        rotate(grid1);
        if (grid1 == grid2) {
            cout << "rotated 180 degrees." << endl;
            continue;
        }

        // rotate 270 degree
        rotate(grid1);
        if (grid1 == grid2) {
            cout << "rotated 270 degrees." << endl;
            continue;
        }

        // reflect
        rotate(grid1); // back to original
        reflect(grid1);
        if (grid1 == grid2) {
            cout << "reflected vertically." << endl;
            continue;
        }

        // reflect + rotate 90 degree
        rotate(grid1);
        if (grid1 == grid2) {
            cout << "reflected vertically and rotated 90 degrees." << endl;
            continue;
        }

        // reflect + rotate 180 degree
        rotate(grid1);
        if (grid1 == grid2) {
            cout << "reflected vertically and rotated 180 degrees." << endl;
            continue;
        }

        // reflect + rotate 270 degree
        rotate(grid1);
        if (grid1 == grid2) {
            cout << "reflected vertically and rotated 270 degrees." << endl;
            continue;
        }

        // no match
        cout << "improperly transformed." << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
