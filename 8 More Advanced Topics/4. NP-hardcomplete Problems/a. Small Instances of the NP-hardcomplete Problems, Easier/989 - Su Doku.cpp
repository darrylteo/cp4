#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> grid;
vector<int> row, col, box;

// make sure the grid is valid by checking if there is any cell with no possible value
// protects against the adversarial case of
// 3
// 1 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 2 3 4 5 6 7 8 9


bool invalid() {
    for (int r = 0; r < n * n; r++) {
        for (int c = 0; c < n * n; c++) {
            int found = 1;
            if (grid[r][c] == 0) {
                found = 0;
                for (int i = 1; i <= n * n; i++) { // try numbers 1 - n * n that are NOT used
                    if (!(row[r] & (1 << i)) && !(col[c] & (1 << i)) && !(box[(r / n) * n + c / n] & (1 << i))) found++;
                }
            }
            if (found == 0) return true; // no possible value for this cell
        }
    }
    return false;
}

bool solve(int id) {
    int r = id / (n * n), c = id % (n * n);
    if (id == n * n * n * n) return true;
    if (grid[r][c] != 0) return solve(id + 1);
    for (int i = 1; i <= n * n; i++) {
        if (!(row[r] & (1 << i)) && !(col[c] & (1 << i)) && !(box[(r / n) * n + c / n] & (1 << i))) {
            grid[r][c] = i;
            row[r] |= 1 << i;
            col[c] |= 1 << i;
            box[(r / n) * n + c / n] |= 1 << i;
            if (solve(id + 1)) return true;
            grid[r][c] = 0;
            row[r] &= ~(1 << i);
            col[c] &= ~(1 << i);
            box[(r / n) * n + c / n] &= ~(1 << i);
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int first = 1;
    while (cin >> n) {
        if (first) first = 0;
        else cout << '\n';
        grid.assign(n * n, vector<int>(n * n, 0));
        row.assign(n * n, 0);
        col.assign(n * n, 0);
        box.assign(n * n, 0);
        for (int i = 0; i < n * n; i++) {
            for (int j = 0; j < n * n; j++) {
                cin >> grid[i][j];
                if (grid[i][j] != 0) {
                    row[i] |= 1 << grid[i][j];
                    col[j] |= 1 << grid[i][j];
                    box[(i / n) * n + j / n] |= 1 << grid[i][j];
                }
            }
        }
        if (invalid() || !solve(0)) cout << "NO SOLUTION\n";
        else {
            for (int i = 0; i < n * n; i++) {
                for (int j = 0; j < n * n; j++) {
                    cout << grid[i][j] << (j == n * n - 1 ? "" : " ");
                }
                cout << '\n';
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}