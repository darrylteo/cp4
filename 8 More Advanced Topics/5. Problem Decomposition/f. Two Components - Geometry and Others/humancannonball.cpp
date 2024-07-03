#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
};

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    point start{}, end{};
    cin >> start.x >> start.y >> end.x >> end.y;
    int n;
    cin >> n;
    vector<point> points(n + 2);
    points[0] = start;
    points[n + 1] = end;
    for (int i = 1; i <= n; i++) cin >> points[i].x >> points[i].y;
    double adj[n + 2][n + 2];
    for (int i = 0; i < n + 2; i++) for (int j = 0; j < n + 2; j++) adj[i][j] = 1e9;
    for (int i = 0; i < n + 2; i++) {
        adj[i][i] = 0;
        adj[0][i] = dist(start, points[i]) / 5; // from start can only run to points
    }
    for (int i = 1; i < n + 2; i++) { // we don't start from start (excl 0)
        for (int j = i + 1; j < n + 2; j++) {
            double run = dist(points[i], points[j]) / 5;
            double cannonAndRun = 2 + abs(dist(points[i], points[j]) - 50) / 5;
            adj[i][j] = adj[j][i] = min(run, cannonAndRun);
        }
    }
    // floyd warshall
    for (int k = 0; k < n + 2; k++) {
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    cout << fixed << setprecision(6) << adj[0][n + 1] << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}