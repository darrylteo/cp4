#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int p[30][30]; // parent
ii grid[30][30]; // weight, cnt
vi ans;

void printPath(int i, int j) {
    if (i != j) printPath(i, p[i][j]);
    ans.push_back(j);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    memset(p, -1, sizeof p);
    memset(grid, 0xf, sizeof grid);
    while (m--) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        u -= 'A', v -= 'A';
        grid[u][v] = grid[v][u] = {w, 1};
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
                p[i][j] = i;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j].first > grid[i][k].first + grid[k][j].first) {
                    grid[i][j].first = grid[i][k].first + grid[k][j].first;
                    grid[i][j].second = grid[i][k].second + grid[k][j].second;
                    p[i][j] = p[k][j];
                } else if (grid[i][j].first == grid[i][k].first + grid[k][j].first) {
                    if (grid[i][j].second > grid[i][k].second + grid[k][j].second) {
                        grid[i][j].second = grid[i][k].second + grid[k][j].second;
                        p[i][j] = p[k][j];
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        char u, v;
        cin >> u >> v;
        u -= 'A', v -= 'A';
        ans.clear();
        printPath(u, v);
        for (int i = 0; i < ans.size(); i++) {
            cout << (char) (ans[i] + 'A');
            if (i + 1 < ans.size()) cout << " ";
        }
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}