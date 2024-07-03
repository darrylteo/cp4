#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
vector<int> ans(1005, 0);

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
    for (int j = 1; j <= m; ++j) ans[p[j]] = j;
    for (int i = 1; i <= n; ++i) {
        if (A[i][ans[i]] == 0) ans[i] = 0; // to indicate that i-th vertex is not matched
    }
    return -v[0];
}

// ref: https://cp-algorithms.com/graph/hungarian-algorithm.html

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n, k;
    cin >> m >> n >> k;
    int invert = 0;
    if (n > m) {
        swap(n, m);
        invert = 1;
    }
    vector<vector<int>> A(n + 1, vector<int>(m + 1, 0));
    while (k--) {
        int u, v, w;
        cin >> u >> v >> w;
        if (!invert) A[u][v] = -w; // we want maximum weight matching
        else A[v][u] = -w;
    }
    // ans
    cout << -hungarian(A) << endl;
    // count num matches
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] != 0) cnt++;
    }
    cout << cnt << endl;
    // if not inverted, can print ans directly
    if (!invert) {
        for (int i = 1; i <= n; i++) {
            if (ans[i] != 0) cout << i << " " << ans[i] << endl;
        }
    } else { // need get all and sort
        vector<pair<int, int>> res;
        for (int i = 1; i <= n; i++) {
            if (ans[i] != 0) res.push_back({ans[i], i});
        }
        sort(res.begin(), res.end());
        for (auto &x: res) {
            cout << x.first << " " << x.second << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
