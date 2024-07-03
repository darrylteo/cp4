#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m, cases = 1;
    while (cin >> n >> m, n) {
        map<string, int> mp;
        int grid[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1e9;
            }
            grid[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;
            if (mp.find(u) == mp.end()) {
                mp[u] = mp.size();
            }
            if (mp.find(v) == mp.end()) {
                mp[v] = mp.size();
            }
            grid[mp[u]][mp[v]] = 1;
            grid[mp[v]][mp[u]] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
        int worst = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                worst = max(worst, grid[i][j]);
            }
        }
        cout << "Network " << cases++ << ": ";
        if (worst == 1e9) {
            cout << "DISCONNECTED\n\n";
        } else {
            cout << worst << "\n\n";
        }

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




