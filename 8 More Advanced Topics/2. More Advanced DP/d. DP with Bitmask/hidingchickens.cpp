#include <bits/stdc++.h>

using namespace std;

struct pt{
    double x, y;
};

int N;
pt pts[21];
double dist[21][21]; // 0-19 for chickens, 20 reserved for root
double memo[1 << 20]; // dp[mask] = min distance to cover remaining nodes

double getDist(int i, int j) {
    return sqrt((pts[i].x - pts[j].x) * (pts[i].x - pts[j].x) + (pts[i].y - pts[j].y) * (pts[i].y - pts[j].y));
}

// assume fox always start at root, can either root - chicken1 - root OR root - chicken1 - chicken2 - root
inline double dp(int mask) {
    if (mask == 0) return 0; // all visited
    if (memo[mask] > -0.5) return memo[mask];
    int c1 = __builtin_ctz(mask); // get index of first set bit
    double res = 2 * dist[20][c1] + dp(mask ^ (1 << c1)); // (root - chicken1 - root) + dp soln with chicken1 visited
    for (int c2 = c1 + 1; c2 <= N; c2++) {
        if (mask & (1 << c2)) {
            // (root - chicken1 - chicken2 - root) + dp soln with chicken1 and chicken2 visited
            res = min(res, dist[20][c1] + dist[c1][c2] + dist[c2][20] + dp(mask ^ (1 << c1) ^ (1 << c2)));
        }
    }
    return memo[mask] = res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> pts[20].x >> pts[20].y;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> pts[i].x >> pts[i].y;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dist[i][j] = dist[j][i] = getDist(i, j);
        }
    }
    for (int i = 0; i < N; i++) dist[20][i] = dist[i][20] = getDist(20, i);
    for (int i = 0; i < (1 << N); i++) memo[i] = -1;
    cout << fixed << setprecision(10) << dp((1 << N) - 1) - *max_element(dist[20], dist[20] + N + 1) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
