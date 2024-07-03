#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

// ref: https://cp-algorithms.com/graph/hungarian-algorithm.html

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, tc = 1;
    while (cin >> n, n) {
        m = n;
        vector<vector<int>> A(n + 1, vector<int>(m + 1));
        vector<pt> pts(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> pts[i].x >> pts[i].y;
        }
        int best = 1e9;
        // for each point, get dist to (1, 1), (2, 2), ..., (n, n)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                A[i][j] = abs(pts[i].x - j) + abs(pts[i].y - j);
            }
        }
        best = min(best, hungarian(A));
        // get the other diagonal
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                A[i][j] = abs(pts[i].x - j) + abs(pts[i].y - (n - j + 1));
            }
        }
        best = min(best, hungarian(A));
        // get all horizontals
        for (int k = 1; k <= n; k++) { // for each row
            for (int i = 1; i <= n; i++) { // for each point
                for (int j = 1; j <= m; j++) { // for each column
                    A[i][j] = abs(pts[i].x - k) + abs(pts[i].y - j);
                }
            }
            best = min(best, hungarian(A));
        }
        // get all verticals
        for (int k = 1; k <= n; k++) { // for each column
            for (int i = 1; i <= n; i++) { // for each point
                for (int j = 1; j <= m; j++) { // for each row
                    A[i][j] = abs(pts[i].x - j) + abs(pts[i].y - k);
                }
            }
            best = min(best, hungarian(A));
        }
        cout << "Board " << tc++ << ": " << best << " moves required.\n\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
