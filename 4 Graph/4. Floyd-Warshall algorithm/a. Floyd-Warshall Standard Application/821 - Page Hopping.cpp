#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // adjacency matrix for floyd warshall

    string buf;
    int grid[101][101], cases = 1;
    while (getline(cin, buf)) {
        if (buf == "0 0") break;
        memset(grid, 0xf, sizeof(grid));
        stringstream ss(buf);
        int n, m, maxIdx = 0;
        while (ss >> n >> m) {
            if (n == 0 && m == 0) break;
            grid[n][m] = 1;
            maxIdx = max(maxIdx, max(n, m));
        }
        for (int k = 1; k <= maxIdx; k++) {
            for (int i = 1; i <= maxIdx; i++) {
                for (int j = 1; j <= maxIdx; j++) {
                    if (grid[i][j] > grid[i][k] + grid[k][j]) {
                        grid[i][j] = grid[i][k] + grid[k][j];
                    }
                }
            }
        }
        int count = 0;
        int sum = 0;
        for (int i = 1; i <= maxIdx; i++) {
            for (int j = 1; j <= maxIdx; j++) {
                if (i != j && grid[i][j] < 200) { // since longest chain is 100
                    count++;
                    sum += grid[i][j];
                }
            }
        }
        cout << "Case " << cases++ << ": average length between pages = ";
        cout << fixed << setprecision(3) << (double) sum / count << " clicks" << '\n';

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}