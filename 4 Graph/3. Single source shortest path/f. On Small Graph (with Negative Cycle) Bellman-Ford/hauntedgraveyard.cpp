#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

// hard qn
// ref: https://github.com/marioyc/Online-Judge-Solutions/blob/master/Live%20Archive/4509%20-%20Haunted%20Graveyard.cpp
// seems like doing AL doesn't work, so do edge list instead

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, V;
    while (cin >> R >> C, R) {
        V = R * C;
        // 0 for hole, -1 for grass, -2 for grave
        int grid[R][C];
        // all grass
        memset(grid, -1, sizeof grid);
        // get grave
        int G;
        cin >> G;
        for (int i = 0; i < G; ++i) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = -2;
        }
        // get haunted holes and add to AL too
        vector<iii> EL;
        int E;
        cin >> E;
        for (int i = 0; i < E; ++i) {
            int x, y, x1, y1, t;
            cin >> x >> y >> x1 >> y1 >> t;
            grid[x][y] = 0;
            EL.emplace_back(x * C + y, x1 * C + y1, t);
        }
        // add grass to AL. 1s to walk grass
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] != -1) continue; // grass -> hole or grass -> grass
                if (i == R-1 && j == C-1) continue; // cannot walk out from end
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dr[k], nj = j + dc[k];
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C && grid[ni][nj] != -2) {
                        EL.emplace_back(i * C + j, ni * C + nj, 1);
                    }
                }
            }
        }
        // bellman ford
        vi dist(V, 1e9);
        dist[0] = 0;
        for (int i = 0; i < V - 1; ++i) {
            for (auto &e : EL) {
                auto[u, v, w] = e;
                if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        // check for negative cycle
        int flag = 0;
        for (auto &e : EL) {
            auto [u, v, w] = e;
            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                cout << "Never" << endl;
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        if (dist[V - 1] ==  1e9) {
            cout << "Impossible" << endl;
        } else cout << dist[V - 1] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}