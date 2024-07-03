#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int dr2[] = {0, 1};
const int dc2[] = {1, 0};
const int dr4[] = {0, 0, 1, -1};
const int dc4[] = {1, -1, 0, 0};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    char grid[n][n];
    ll parentCnt[n][n];
    vii adj[n][n];
    int inDeg[n][n];
    memset(inDeg, 0, sizeof inDeg);
    memset(parentCnt, 0, sizeof parentCnt);
    for (int i = 0; i < n; ++i) cin >> grid[i];
    // need some preprocessing with bfs (to avoid bad/unvisited nodes)
    int dist[n][n], visited[n][n];
    memset(dist, -1, sizeof dist);
    memset(visited, 0, sizeof visited);
    dist[0][0] = 0;
    queue<ii> q1;
    q1.emplace(0, 0);
    while (!q1.empty()) {
        auto [r, c] = q1.front();
        q1.pop();
        if (visited[r][c]) continue;
        visited[r][c] = 1;
        for (int k = 0; k < 2; ++k) {
            int nr = r + dr2[k];
            int nc = c + dc2[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] != '#' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q1.emplace(nr, nc);
            }
        }
    }
    // get adj list and inDeg
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == -1) continue;
            for (int k = 0; k < 2; ++k) {
                int ni = i + dr2[k];
                int nj = j + dc2[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && dist[ni][nj] != -1) {
                    adj[i][j].emplace_back(ni, nj);
                    inDeg[ni][nj]++;
                }
            }
        }
    }
    // count num parent paths
    queue<ii> q;
    q.emplace(0, 0);
    parentCnt[0][0] = 1;
    while (!q.empty()) {
        auto [ur, uc] = q.front();
        q.pop();
        for (auto &[vr, vc] : adj[ur][uc]) {
            parentCnt[vr][vc] += parentCnt[ur][uc] % INT_MAX;
            if (--inDeg[vr][vc] == 0) q.emplace(vr, vc);
        }
    }
    if (dist[n - 1][n - 1] != -1) {
        cout << parentCnt[n - 1][n - 1] % INT_MAX << endl;
        return 0;
    }
    // if cannot reach, check if 4 dir can reach or not
    memset(dist, -1, sizeof dist);
    memset(visited, 0, sizeof visited);
    dist[0][0] = 0;
    queue<ii> q2;
    q2.emplace(0, 0);
    while (!q2.empty()) {
        auto [r, c] = q2.front();
        q2.pop();
        if (visited[r][c]) continue;
        visited[r][c] = 1;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr4[k];
            int nc = c + dc4[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] != '#' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q2.emplace(nr, nc);
            }
        }
    }
    if (dist[n - 1][n - 1] != -1) {
        cout << "THE GAME IS A LIE" << endl;
    } else {
        cout << "INCONCEIVABLE" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
