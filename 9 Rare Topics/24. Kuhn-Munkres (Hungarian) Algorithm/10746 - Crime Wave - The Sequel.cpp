#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9;

// ref: https://cp-algorithms.com/graph/hungarian-algorithm.html
// direct application with template code

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m, n) {
        vector<vector<ld>> A(n + 1, vector<ld>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> A[i][j];
            }
        }

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
        vector<int> ans(n + 1);
        for (int j = 1; j <= m; ++j) ans[p[j]] = j;
        cout << fixed << setprecision(2) << round(-v[0] / n * 100 + 1e-6) / 100 << '\n'; // careful rounding
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
