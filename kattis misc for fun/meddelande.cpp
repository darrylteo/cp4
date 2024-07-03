#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for (auto &row: grid) {
        for (auto &cell: row) {
            cin >> cell;
        }
    }
    string ans;
    // comb down the right diagonals
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N && j - i >= 0; ++i) {
            if (grid[i][j - i] != '.') ans += grid[i][j - i];
        }
    }
    // second half
    for (int i = 1; i < N; ++i) {
        for (int j = M - 1; j >= 0 && i + M - 1 - j < N; --j) {
            if (grid[i + M - 1 - j][j] != '.') ans += grid[i + M - 1 - j][j];
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
