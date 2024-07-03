#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> factors(1005), row, grid;
vector<int> X(16), Y(16), used;
int N, done;

void dfs(int col) {
    if (done) return;
    if (col == N) {
        done = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << setw(4) << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    // for current col, choose 2 rows to put factors in
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (row[i].size() == 2 || row[j].size() == 2) continue; // if row already has 2 factors, skip
            for (int fac: factors[X[col]]) {
                int a = fac;
                int b = X[col] / a;
                if (a == b || used[a] || used[b]) continue;  // cannot have same number in grid at all
                used[a] = used[b] = 1;
                grid[i][col] = a;
                grid[j][col] = b;
                row[i].push_back(a);
                row[j].push_back(b);
                // don't bother if row already has 2 factors and not equal to target Y
                if (row[i].size() == 2 && row[i][0] * row[i][1] != Y[i] ||
                    row[j].size() == 2 && row[j][0] * row[j][1] != Y[j] ||
                    Y[i] % a || Y[j] % b) {} // surprising... pruning when only 1 factor. easy to miss.
                else dfs(col + 1);
                used[a] = used[b] = 0;
                grid[i][col] = 0;
                grid[j][col] = 0;
                row[i].pop_back();
                row[j].pop_back();
            }
        }
    }
}

// place each factor, and it's pair in 2 chosen rows. we go column by column (so it's guaranteed ok in each col)
// we prune if a row has 2 factors already and is not equal to target Y
// ref: https://morris821028.github.io/2014/09/11/oj/uva/uva-10571/

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < 1005; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) factors[i].push_back(j);
        }
    }
    while (cin >> N, N) {
        grid.assign(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) cin >> X[i];
        for (int i = 0; i < N; i++) cin >> Y[i];
        used.assign(1005, 0);
        row.assign(N, vector<int>());
        done = 0;
        dfs(0);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}