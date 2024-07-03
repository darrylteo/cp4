#include <bits/stdc++.h>

using namespace std;

struct state {
    int dist, node, boots;

    bool operator<(const state &other) const {
        if (dist != other.dist) return dist < other.dist; // less distance is preferred
        if (boots != other.boots) return boots > other.boots; // more boots is preferred
        return node < other.node; // doesn't matter
    }
};

// finally solved 1 myself xd...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int A, B, M, L, K;
        cin >> A >> B >> M >> L >> K;
        // distNorm stores the APSP. distFast stores the APSP with villages as intermediate nodes. 1 based today.
        vector<vector<int>> distNorm(A + B + 1, vector<int>(A + B + 1, 1e9)),
                distFast(A + B + 1, vector<int>(A + B + 1, 1e9));
        for (int i = 1; i <= A + B; ++i) {
            distNorm[i][i] = 0;
            distFast[i][i] = 0;
        }
        for (int i = 1; i <= M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            distNorm[u][v] = w;
            distNorm[v][u] = w;
            distFast[u][v] = w;
            distFast[v][u] = w;
        }
        // floyd warshall to get the APSPs
        for (int k = 1; k <= A + B; ++k) {
            for (int i = 1; i <= A + B; ++i) {
                for (int j = 1; j <= A + B; ++j) {
                    distNorm[i][j] = min(distNorm[i][j], distNorm[i][k] + distNorm[k][j]);
                    if (k <= A)
                        distFast[i][j] = min(distFast[i][j], distFast[i][k] + distFast[k][j]); // village intermediate
                }
            }
        }
        // get adjacency list
        vector<vector<int>> adjNorm(A + B + 1), adjFast(A + B + 1);
        for (int i = 1; i <= A + B; ++i) {
            for (int j = i + 1; j <= A + B; ++j) {
                if (distNorm[i][j] < 1e9) {
                    adjNorm[i].push_back(j);
                    adjNorm[j].push_back(i);
                }
                if (distFast[i][j] <= L) {
                    adjFast[i].push_back(j);
                    adjFast[j].push_back(i);
                }
            }
        }
        // starts at village A+B and ends at village 1, with K uses of boots
        set<state> pq;
        pq.insert({0, A + B, K});
        vector<vector<int>> dist(A + B + 1, vector<int>(K + 1, 1e9));
        for (int k = 0; k <= K; ++k) dist[A + B][k] = 0;
        while (!pq.empty()) {
            auto top = *pq.begin();
            pq.erase(pq.begin());
            int d = top.dist, u = top.node, b = top.boots;
            if (dist[u][b] < d) continue;
            if (u == 1) break; // we have reached the destination
            if (b > 0) { // if we have boots, we can use them
                for (int v: adjFast[u]) { // possible places to visit using boots (<= L)
                    if (u == v) continue;
                    int found = 0;
                    for (int j = 0; j <= b - 1; ++j) { // use "one or more" boots to visit v in 0 time
                        if (d < dist[v][j]) { // distance travelled is same as go to u but use boots
                            dist[v][j] = d;
                            found = 1;
                        }
                    }
                    if (found) pq.insert({dist[v][b - 1], v, b - 1}); // just use 1 boot
                }
            }
            for (int v: adjNorm[u]) { // normal dijkstra stuff
                if (d + distNorm[u][v] < dist[v][b]) {
                    dist[v][b] = d + distNorm[u][v];
                    pq.insert({dist[v][b], v, b});
                }
            }
        }
        int best = 1e9;
        for (int i = 0; i <= K; ++i) best = min(best, dist[1][i]);
        cout << best << endl; // guaranteed to have a solution
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
