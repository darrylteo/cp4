#include <bits/stdc++.h>

using namespace std;

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};

struct pt {
    int x, y;
};

const int INF = 1e9;

int hungarian(vector<vector<int>> &A) {
    int n = A.size() - 1;
    int m = A[0].size() - 1;
    vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(m + 1, INF);
        vector<bool> used(m + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    int cur = A[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    return -v[0];
}

// return shortest dist from b to all X, 1e7 if not reachable
// just bfs the graph, then check for each X if it is reachable
// prefer bfs to dijkstra as the graph is unweighted
vector<int> bfs(vector<string> &grid, int br, int bc, vector<pt> &X) {
    int R = grid.size(), C = grid[0].size();
    vector<vector<int>> dist(R, vector<int>(C, 1e7));
    dist[br][bc] = 0;
    queue<pt> q;
    q.push({br, bc});
    while (!q.empty()) {
        pt u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = u.x + dirr[i];
            int nc = u.y + dirc[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != '#') {
                if (dist[nr][nc] == 1e7) { // not visited
                    dist[nr][nc] = dist[u.x][u.y] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<int> res;
    for (auto &x : X) {
        res.push_back(dist[x.x][x.y]);
    }
    return res;
}

// ref: https://cp-algorithms.com/graph/hungarian-algorithm.html

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int r, c;
        cin >> r >> c;
        vector<string> grid(r);
        for (int i = 0; i < r; i++) cin >> grid[i];
        vector<pt> B, X;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'B') B.push_back({i, j});
                if (grid[i][j] == 'X') X.push_back({i, j});
            }
        }
        vector<vector<int>> A(B.size() + 1, vector<int>(X.size() + 1));
        for (int i = 0; i < B.size(); i++) {
            vector<int> dist = bfs(grid, B[i].x, B[i].y, X);
            for (int j = 0; j < X.size(); j++) {
                A[i + 1][j + 1] = dist[j];
            }
        }
        int ans = hungarian(A);
        if (ans > 1e7) cout << "impossible\n";
        else cout << ans << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
