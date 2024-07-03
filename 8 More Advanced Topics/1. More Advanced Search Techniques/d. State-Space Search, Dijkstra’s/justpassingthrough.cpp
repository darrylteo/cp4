#include <bits/stdc++.h>

using namespace std;

const int dirr[] = {0, 1, -1};
const int dirc[] = {1, 1, 1};
int dist[505][505][15]; // dist[r][c][n] = min dist to reach (r, c) after going through n passes. once more than N passes it's a bad soln

struct state {
    int d, r, c, n;

    state(int d, int r, int c, int n) : d(d), r(r), c(c), n(n) {}

    bool operator<(const state &other) const {
        if (d != other.d) return d < other.d; // smaller dist preferred
        if (n != other.n) return n > other.n; // more passes preferred
        if (r != other.r) return r < other.r; // doesn't matter
        return c < other.c; // doesn't matter
    }
};

// almost time limit -_-

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, N;
    cin >> R >> C >> N;
    vector<vector<int>> grid(R, vector<int>(C)), pass(R, vector<int>(C, 0));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i < R - 1; ++i) {
        for (int j = 1; j < C - 1; ++j) {
            if (grid[i][j] < grid[i - 1][j] && grid[i][j] < grid[i + 1][j] &&
                grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i][j + 1] && grid[i][j] != -1 &&
                grid[i - 1][j] != -1 && grid[i + 1][j] != -1 &&
                grid[i][j - 1] != -1 && grid[i][j + 1] != -1) {
                pass[i][j] = 1;
            }
        }
    }
    set<state> pq;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < R; ++i) { // start from any cell in the first column
        if (grid[i][0] != -1) {
            dist[i][0][0] = grid[i][0];
            pq.emplace(grid[i][0], i, 0, 0);
        }
    }
    while (!pq.empty()) {
        auto [d, r, c, n] = *pq.begin();
        pq.erase(pq.begin());
        if (dist[r][c][n] < d) continue;
        if (n > N) continue; // bad soln
        if (c == C - 1 && n == N) {
            cout << d << endl;
            return 0;
        }
        for (int i = 0; i < 3; ++i) {
            int rr = r + dirr[i], cc = c + dirc[i];
            if (rr < 0 || rr >= R || cc < 0 || cc >= C || grid[rr][cc] == -1) continue;
            if (pass[rr][cc]) {
                int nn = min(n + 1, N + 1);
                if (dist[rr][cc][nn] > d + grid[rr][cc]) {
                    dist[rr][cc][nn] = d + grid[rr][cc];
                    pq.emplace(dist[rr][cc][nn], rr, cc, nn);
                }
            } else {
                if (dist[rr][cc][n] > d + grid[rr][cc]) {
                    dist[rr][cc][n] = d + grid[rr][cc];
                    pq.emplace(d + grid[rr][cc], rr, cc, n);
                }
            }
        }
    }
    cout << "impossible\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
