#include <bits/stdc++.h>

using namespace std;

// just follow question

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, start = 1;
    while (cin >> n, n) {
        if (start != 1) cout << endl;
        start = 0;
        vector<vector<vector<int>>> g(n, vector<vector<int>>(n, vector<int>(n)));
        int x = n / 2 - 1, y = n / 2, z = n - 2, id = 1; // middle of bottom of cube
        while (true) {
            if (g[(x + 1) % n][y][(z + 1) % n] == 0) { // next layer, go right
                g[(x + 1) % n][y][(z + 1) % n] = id++;
                x = (x + 1) % n;
                z = (z + 1) % n;
            } else if (g[x][(y + 1) % n][(z + 1) % n] == 0) { // next layer, go up
                g[x][(y + 1) % n][(z + 1) % n] = id++;
                y = (y + 1) % n;
                z = (z + 1) % n;
            } else if (g[x][y][(z - 1 + n) % n] == 0) { // previous layer
                g[x][y][(z - 1 + n) % n] = id++;
                z = (z - 1 + n) % n;
            } else {
                break;
            }
        }
        // print
        for (int i = 0; i < n; i++) {
            if (i) cout << endl;
            for (int j = n - 1; j >= 0; j--) { // messed up the j earlier
                if (j != n - 1) cout << endl;
                for (int k = 0; k < n; k++) {
                    if (k) cout << " ";
                    cout << setw(5) << g[k][j][i];
                }
            }
            cout << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
