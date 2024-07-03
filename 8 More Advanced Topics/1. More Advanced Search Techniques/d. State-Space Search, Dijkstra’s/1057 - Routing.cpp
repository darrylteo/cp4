#include <bits/stdc++.h>

using namespace std;

// ref: https://www.cnblogs.com/LSlzf/p/11677078.html
// main idea. let dist[i][j] store the num of nodes covered for 1 walk to i and j walk to 1.
// the j walk to 1 is computed using inverse of adjacency list
// dist[i2][j] = min(dist[i2][j], dist[i][j] + (i2!=j)) // walk normal graph i to i2 to new spot and see if can 'recycle' node j
// dist[i][j2] = min(dist[i][j2], dist[i][j] + (j2!=i)) // walk inverse graph j to j2 to new spot and see if can 'recycle' node i
// dist[i][j] = min(dist[i][j], dist[j][i] + floyd[j][i] - 1)
// last line is the unexpected part. LHS is 1 to i and j to 1. RHS is 1 to j, then j to i, then i to 1!!!
// this saves steps if j to 1 was so long to the point it was better to walk 1 round from 1 to j to i to 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, cases = 1;
    while (cin >> n >> m, n) {
        vector<vector<int>> adj(n), inv(n);
        vector<vector<int>> floyd(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) floyd[i][i] = 0;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--; // later find route from 0 to 1 and 1 to 0 instead
            adj[a].push_back(b);
            inv[b].push_back(a);
            floyd[a][b] = 1;
        }
        // APSP floyd
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                }
            }
        }
        cout << "Network " << cases++ << '\n';
        if (floyd[0][1] == 1e9 || floyd[1][0] == 1e9) { // impossible to reach 1 from 0 or 0 from 1
            cout << "Impossible\n\n";
            continue;
        }
        // dijkstra
        set<tuple<int, int, int>> pq; // dist, i, j
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // 0 to 0 on normal, and 0 to 0 on reverse covers node 0.
        // our goal is dist[1][1] ... num covered when 0 walk to 1 on normal and 0 walk to 1 on reverse (aka 0 walk to 1 and 1 walk to 0)
        dist[0][0] = 1;
        pq.insert({1, 0, 0});
        while (!pq.empty()) {
            auto [d, i, j] = *pq.begin();
            pq.erase(pq.begin());
            if (d > dist[i][j]) continue;
            for (int i2 : adj[i]) {
                if (dist[i2][j] > dist[i][j] + (i2 != j)) {
                    pq.erase({dist[i2][j], i2, j});
                    dist[i2][j] = dist[i][j] + (i2 != j);
                    pq.insert({dist[i2][j], i2, j});
                }
            }
            for (int j2 : inv[j]) {
                if (dist[i][j2] > dist[i][j] + (j2 != i)) {
                    pq.erase({dist[i][j2], i, j2});
                    dist[i][j2] = dist[i][j] + (j2 != i);
                    pq.insert({dist[i][j2], i, j2});
                }
            }
            if (dist[i][j] > dist[j][i] + floyd[j][i] - 1 && i != j) { // when i == j then it decrease forever since floyd[i][i] = 0
                pq.erase({dist[i][j], i, j});
                dist[i][j] = dist[j][i] + floyd[j][i] - 1;
                pq.insert({dist[i][j], i, j});
            }
        }
        cout << "Minimum number of nodes = " << dist[1][1] << "\n\n";
    }
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}

