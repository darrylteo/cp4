#include <bits/stdc++.h>

using namespace std;

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                if (grid[i][j] < grid[i + dirx[k]][j + diry[k]]) {
                    cnt++;
                }
            }
            if (cnt == 4) {
                cout << "Jebb" << endl;
                return 0;
            }
        }
    }
    cout << "Neibb" << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
