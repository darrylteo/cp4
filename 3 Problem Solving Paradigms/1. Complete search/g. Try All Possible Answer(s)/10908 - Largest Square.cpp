#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int M, N, Q;
        cin >> M >> N >> Q;
        cout << M << " " << N << " " << Q << endl;
        vector<vector<char>> grid(M, vector<char>(N));
        for (auto &row: grid) {
            for (auto &cell: row) {
                cin >> cell;
            }
        }
        while (Q--) {
            int x, y;
            cin >> x >> y;
            char c = grid[x][y];
            int ans = 1;
            for (int i = 1; i < M || i < N; ++i) {
                bool flag = true;
                for (int j = x - i; j <= x + i; ++j) {
                    for (int k = y - i; k <= y + i; ++k) {
                        if (j < 0 || j >= M || k < 0 || k >= N || grid[j][k] != c) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag) ans = 2 * i + 1;
                else break;
            }
            cout << ans << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}