#include <bits/stdc++.h>

using namespace std;

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};
int N, X, Y, sx, sy, tx, ty;
vector<vector<int>> dist;

int sssp(int mdis) {
    vector<vector<int>> dist2(X, vector<int>(Y, -1));
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    dist2[sx][sy] = 0;
    if (dist[sx][sy] < mdis) return -1; // might start on enemy
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirr[i], ny = y + dirc[i];
            if (nx >= 0 && nx < X && ny >= 0 && ny < Y && dist2[nx][ny] == -1 && dist[nx][ny] >= mdis) {
                dist2[nx][ny] = dist2[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    return dist2[tx][ty];
}

// follow book. MSSP unweighted, then BSTA with condition on max closeness

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N >> X >> Y >> sx >> sy >> tx >> ty;
    queue<pair<int, int>> q;
    dist.assign(X, vector<int>(Y, -1));
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        dist[x][y] = 0;
        q.emplace(x, y);
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirr[i], ny = y + dirc[i];
            if (nx >= 0 && nx < X && ny >= 0 && ny < Y && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    int l = 0, r = 2000;
    while (l < r - 1) {
        int m = l + (r - l) / 2;
        if (sssp(m) == -1) r = m - 1;
        else l = m;
    }
    if (sssp(r) != -1) cout << r << ' ' << sssp(r) << endl;
    else cout << l << ' ' << sssp(l) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
