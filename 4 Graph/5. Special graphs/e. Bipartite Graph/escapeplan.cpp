#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi AL[405];
int match[405], vis[405];

inline int Aug(int L) {
    if (vis[L]) return 0;                          // L visited, return 0
    vis[L] = 1;
    for (auto &R: AL[L])
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L;                              // flip status
            return 1;                                  // found 1 matching
        }
    return 0;                                      // no matching
}

// another direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, cases = 1;
    while (cin >> n, n) {
        cout << "Scenario " << cases++ << endl;
        vector<pair<double, double>> robots, holes;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            robots.emplace_back(x, y);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            double x, y;
            cin >> x >> y;
            holes.emplace_back(x, y);
        }
        vector<vector<double>> dist(n, vector<double>(m)); // dist[i][j] = distance between robot i and hole j
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[i][j] = sqrt((robots[i].first - holes[j].first) * (robots[i].first - holes[j].first) +
                                  (robots[i].second - holes[j].second) * (robots[i].second - holes[j].second));
            }
        }
        for (int t: {5, 10, 20}) {
            for (int i = 0; i < n; i++) {
                AL[i].clear();
                for (int j = 0; j < m; j++) {
                    if (dist[i][j] <= t * 10) { // 10m/s
                        AL[i].push_back(j);
                    }
                }
            }
            unordered_set<int> freeV;
            for (int i = 0; i < n; i++) {
                freeV.insert(i);
            }
            memset(match, -1, sizeof match);
            int MCBM = 0;
            for (auto &f: freeV) {                        // (in random order)
                memset(vis, 0, sizeof vis);                  // reset before each recursion
                MCBM += Aug(f);                              // try to match f
            }
            cout << "In " << t << " seconds " << MCBM << " robot(s) can escape" << endl;
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

