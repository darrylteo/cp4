#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// 1 if can reach, 0 if cannot reach

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        n += 2;
        vii points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        int grid[n][n];
        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
                if (dist <= 1000) {
                    grid[i][j] = 1;
                    grid[j][i] = 1;
                }
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] |= (grid[i][k] & grid[k][j]);
                }
            }
        }
        if (grid[0][n - 1]) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




