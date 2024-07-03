#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> attack(const vector<vector<int>> &grid, int N) {
    vector<vector<int>> newGrid;
    newGrid = grid;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (i > 0 && grid[i - 1][j] == (grid[i][j] + 1) % N) { // up
                newGrid[i - 1][j] = grid[i][j];
            }
            if (i < grid.size() - 1 && grid[i + 1][j] == (grid[i][j] + 1) % N) { // down
                newGrid[i + 1][j] = grid[i][j];
            }
            if (j > 0 && grid[i][j - 1] == (grid[i][j] + 1) % N) { // left
                newGrid[i][j - 1] = grid[i][j];
            }
            if (j < grid[0].size() - 1 && grid[i][j + 1] == (grid[i][j] + 1) % N) { // right
                newGrid[i][j + 1] = grid[i][j];
            }
        }
    }
    return newGrid;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N, R, C, K;
    while (cin >> N >> R >> C >> K, N) {
        vector<vector<int>> grid(R, vector<int>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < K; ++i) {
            grid = attack(grid, N);
        }
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C - 1; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << grid[i][C - 1] << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
