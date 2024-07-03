#include <bits/stdc++.h>

using namespace std;

// NESW
vector<int> dir4x = {-1, 0, 1, 0}, dir4y = {0, 1, 0, -1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        map<tuple<int, int, int>, int> dist; // (x, y, k_left), dist
        dist[{0, 0, k}] = 0;
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, k);
        int found = 0;
        while (!q.empty()) {
            auto [x, y, k_left] = q.front();
            if (x == n - 1 && y == m - 1) {
                cout << dist[{x, y, k_left}] << endl;
                found = 1;
                break;
            }
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir4x[i], ny = y + dir4y[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (grid[nx][ny] == 1) {
                    if (k_left > 0) {
                        if (dist.find({nx, ny, k_left - 1}) == dist.end()) {
                            dist[{nx, ny, k_left - 1}] = dist[{x, y, k_left}] + 1;
                            q.emplace(nx, ny, k_left - 1);
                        }
                    }
                } else {
                    if (dist.find({nx, ny, k}) == dist.end()) { // reset k if land on 0
                        dist[{nx, ny, k}] = dist[{x, y, k_left}] + 1;
                        q.emplace(nx, ny, k);
                    }
                }
            }
        }
        if (!found) cout << -1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}