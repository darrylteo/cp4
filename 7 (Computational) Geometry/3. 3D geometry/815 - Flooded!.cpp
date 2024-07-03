#include <bits/stdc++.h>

using namespace std;

// naively increase water level by 1 at a time

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, cases = 1;
    while (cin >> n >> m, n) {
        vector<vector<int>> grid(n, vector<int>(m));
        double height = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                height = min(height, (double) grid[i][j]);
            }
        }
        double vol;
        cin >> vol;
        vol /= 100; // so each square takes up 1 unit area
        while (true) {
            // count squares that are at current height or below
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] <= height) {
                        count++;
                    }
                }
            }
            // fill them up by 1 unit if enough volume. else fill halfway and break
            if (count >= vol) {
                height += vol / count;
                break;
            } else {
                vol -= count;
                height += 1;
            }
        }
        cout << "Region " << cases++ << '\n';
        cout << "Water level is " << fixed << setprecision(2) << height << " meters.\n";
        // get count again
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] <= height) {
                    count++;
                }
            }
        }
        cout << 100.0 * count / (n * m) << " percent of the region is under water.\n\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
