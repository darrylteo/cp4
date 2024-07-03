#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld INF = 1e15;

ll N, S, T, Q;

struct pt {
    ll x, y, z;
};

ld getDist(pt a, pt b) {
    if (a.z <= b.z) return 1e9; // must go downhill
    ld ans = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
    if (ans > Q) return 1e9;
    return ans;
}

ld hungarian(vector<vector<ld>> &A) {
    int n = A.size() - 1, m = A[0].size() - 1;
    vector<int> p(m + 1), way(m + 1);
    vector<ld> u(n + 1), v(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<ld> minv(m + 1, INF);
        vector<bool> used(m + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1;
            ld delta = INF;
            for (int j = 1; j <= m; ++j)
                if (!used[j]) {
                    ld cur = A[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for (int j = 0; j <= m; ++j)
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
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

// ref: https://cp-algorithms.com/graph/hungarian-algorithm.html
// WA many times because i tried to match spring to towns... but it MUST be towns to springs
// got a clue from wikipedia there was a line: assert(J <= W);

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> N >> S >> T >> Q;
    if (T > S || N == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<pt> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i].x >> pts[i].y >> pts[i].z;
    }
    vector<int> a(S), b(T);
    for (int i = 0; i < S; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < T; i++) {
        cin >> b[i];
        b[i]--;
    }
    // calculate distance between all points
    vector<vector<ld>> dist(N, vector<ld>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = getDist(pts[i], pts[j]);
        }
    }
    // floyd. bfs from each spring would be ok too
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<vector<ld>> A(T + 1, vector<ld>(S + 1));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < S; j++) {
            A[i + 1][j + 1] = dist[a[j]][b[i]];
        }
    }
    ld ans = hungarian(A);
    if (ans >= 1e9) cout << "IMPOSSIBLE" << endl;
    else cout << fixed << setprecision(10) << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
