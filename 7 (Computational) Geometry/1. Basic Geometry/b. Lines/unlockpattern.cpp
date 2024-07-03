#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int grid[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    double dist = 0;
    int x, y;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (grid[j][k] == 1) {
                x = j;
                y = k;
                break;
            }
        }
    }
    for (int i = 2; i <= 9; ++i) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (grid[j][k] == i) {
                    dist += hypot(j - x, k - y);
                    x = j;
                    y = k;
                }
            }
        }
    }
    cout << fixed << setprecision(10) << dist << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}