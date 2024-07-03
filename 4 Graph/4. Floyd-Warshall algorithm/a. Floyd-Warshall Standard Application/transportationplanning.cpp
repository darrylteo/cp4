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

    int n, m;
    while (cin >> n, n) {
        vii points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        vector<vector<double>> gridAll(n, vector<double>(n, 1e9));
        vector<vector<double>> grid(n, vector<double>(n, 1e9));
        for (int i = 0; i < n; i++) {
            gridAll[i][i] = 0;
            grid[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gridAll[i][j] = gridAll[j][i] = sqrt(
                        (points[i].first - points[j].first) * (points[i].first - points[j].first) +
                        (points[i].second - points[j].second) * (points[i].second - points[j].second));
            }
        }
        // deal with original road
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            grid[u][v] = gridAll[u][v];
            grid[v][u] = gridAll[v][u];
        }
        // get all missing roads (for later)
        vii missing;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (grid[i][j] == 1e9) {
                    missing.emplace_back(i, j);
                }
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
        double timeOriginal = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                timeOriginal += grid[i][j];
            }
        }
        // add 1 at a time and get best time
        double bestTime = timeOriginal, curTime;
        ii bestAddition;
        for (auto &i : missing) {
            curTime = 0;
            for (int u = 0; u < n; u++) {
                for (int v = u + 1; v < n; v++) {
                    double w = gridAll[i.first][i.second];
                    curTime += min(grid[u][i.second] + w + grid[i.first][v], min(grid[u][v], grid[u][i.first] + w + grid[i.second][v]));
                }
            }
            if (curTime < bestTime) {
                bestTime = curTime;
                bestAddition = i;
            }
        }

        if (fabs(bestTime - timeOriginal) < 1e-9) {
            cout << "no addition reduces " << fixed << setprecision(8) << bestTime << endl;
        } else {
            cout << "adding " << bestAddition.first << " " << bestAddition.second << " reduces " << fixed
                 << setprecision(8) << timeOriginal << " to " << bestTime << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




