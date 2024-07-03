#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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

int dist(pt a, pt b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// ref: https://cp-algorithms.com/graph/hungarian-algorithm.html

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pt> b(N), c(M); // bottles, couriers.
    for (int i = 0; i < N; i++) {
        cin >> b[i].x >> b[i].y;
    }
    for (int i = 0; i < M; i++) {
        cin >> c[i].x >> c[i].y;
    }
    pt rest{};
    cin >> rest.x >> rest.y;
    vector<vector<int>> cost(N + 1, vector<int>(N + M - 1 + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { // courier to bottle to restaurant.
            cost[i + 1][j + 1] = dist(c[j], b[i]) + dist(b[i], rest);
        }
        for (int j = 0; j < N - 1; j++) { // rest to bot to rest
            cost[i + 1][M + j + 1] = 2 * dist(b[i], rest);
        }
    }
    cout << hungarian(cost) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
