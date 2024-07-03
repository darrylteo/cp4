#include <bits/stdc++.h>

using namespace std;

int T, W;
struct sen {
    int x, y, r;
};
vector<sen> sens;
double adj[1005][1005]; // more than this diameter to reach node j from i
int vis[1005];

void bfs(int i, double d) { // all nodes reachable from left would be marked visited.
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < sens.size(); v++) {
            if (adj[u][v] <= d && !vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

bool canReach(double d) { // if can reach, too fat, reduce d
    memset(vis, 0, sizeof(vis));
    vector<int> leftIdx, rightIdx;
    for (int i = 0; i < sens.size(); i++) {
        if (sens[i].x - sens[i].r <= d) leftIdx.push_back(i);
        if (sens[i].x + sens[i].r >= W - d) rightIdx.push_back(i);
    }
    for (int i : leftIdx) bfs(i, d);
    for (int i : rightIdx) {
        if (vis[i]) return true;
    }
    return false;
}

// start from left wall, check if we can reach right wall using person of person diameter d. if can reach, must reduce d
// from left node, check against all other nodes (and then from these nodes) bfs or dfs.
// visited vector or UFDS.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> W;
        sens.clear();
        memset(adj, 0, sizeof(adj));
        int x, y, r;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            sens.push_back({x, y, r});
        }
        for (int i = 0; i < sens.size(); i++) {
            for (int j = i + 1; j < sens.size(); j++) {
                double dist = sqrt(pow(sens[i].x - sens[j].x, 2) + pow(sens[i].y - sens[j].y, 2));
                adj[i][j] = adj[j][i] = max(0.0, dist - sens[i].r - sens[j].r);
            }
        }
        double lo = 0, hi = W;
        while (hi - lo > 1e-7) {
            double mid = (lo + hi) / 2;
            if (canReach(mid)) hi = mid;
            else lo = mid;
        }
        cout << fixed << setprecision(10) << lo/2 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

