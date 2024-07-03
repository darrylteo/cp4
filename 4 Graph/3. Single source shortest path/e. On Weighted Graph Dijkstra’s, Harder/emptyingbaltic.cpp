#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int dr8[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};

// minimize the highest value in the path
// straightforward for 5.4 difficulty on kattis

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C)), dist(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    int sr, sc;
    cin >> sr >> sc;
    sr--, sc--;
    dist[sr][sc] = grid[sr][sc];
    priority_queue<iii, viii, greater<iii>> pq;
    pq.push({dist[sr][sc], sr, sc});
    while (!pq.empty()) {
        auto [d, r, c] = pq.top();
        pq.pop();
        if (d > dist[r][c]) continue;
        for (int i = 0; i < 8; i++) {
            int nr = r + dr8[i], nc = c + dc8[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                int nd = max(d, grid[nr][nc]);
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans += dist[i][j];
        }
    }
    cout << -ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}