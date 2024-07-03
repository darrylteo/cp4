#include <bits/stdc++.h>

using namespace std;

char bestChar(vector<char> &unavailable) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (find(unavailable.begin(), unavailable.end(), c) == unavailable.end()) {
            return c;
        }
    }
    return '0';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        cout << "Case " << cases << ":\n";
        int n;
        cin >> n;
        vector<vector<char>> grid(n, vector<char>(n));
        for (auto &row: grid) {
            for (auto &cell: row) {
                cin >> cell;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '.') continue;
                vector<char> unavailable;
                if (i + 1 < n) {
                    if (grid[i + 1][j] != '.') unavailable.push_back(grid[i + 1][j]);
                }
                if (i - 1 >= 0) {
                    if (grid[i - 1][j] != '.') unavailable.push_back(grid[i - 1][j]);
                }
                if (j + 1 < n) {
                    if (grid[i][j + 1] != '.') unavailable.push_back(grid[i][j + 1]);
                }
                if (j - 1 >= 0) {
                    if (grid[i][j - 1] != '.') unavailable.push_back(grid[i][j - 1]);
                }
                grid[i][j] = bestChar(unavailable);
            }
        }
        for (auto &row: grid) {
            for (auto &cell: row) {
                cout << cell;
            }
            cout << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
