#include <bits/stdc++.h>

using namespace std;

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};

// code fast but need 3 important insights:
// use 0-1 bfs instead of dijkstra
// steiner mentioned in book
// outside walk to each other is 0 dist can use '.' representation

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C;
        // outside are '.' which are 0 dist to each other
        vector<vector<char>> grid(R + 2, vector<char>(C + 2, '.'));
        vector<pair<int, int>> s; // start points
        s.emplace_back(0, 0);
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '$') s.emplace_back(i, j);
            }
        }
        // dist matrix for each start point
        vector<vector<vector<int>>> dist;
        for (int i = 0; i < s.size(); ++i) {
            vector<vector<int>> currDist(R + 2, vector<int>(C + 2, INT_MAX));
            deque<pair<int, int>> q;
            q.emplace_back(s[i]);
            currDist[s[i].first][s[i].second] = 0;
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop_front();
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dirr[k], nc = c + dirc[k];
                    if (nr >= 0 && nr <= R + 1 && nc >= 0 && nc <= C + 1 && grid[nr][nc] != '*') {
                        if (currDist[nr][nc] <= currDist[r][c] + (grid[nr][nc] == '#')) continue; // worse
                        currDist[nr][nc] = currDist[r][c] + (grid[nr][nc] == '#');
                        if (grid[nr][nc] == '#') q.emplace_back(nr, nc); // increase dist, add back (normal)
                        else q.emplace_front(nr, nc); // 0 dist, add front (new technique)
                    }
                }
            }
            dist.push_back(currDist);
        }
        // try each pair of start points + 1 steiner point
        // -2 because we counted the steiner point 3 times when we should have counted it only once
        int ans = 1e9;
        for (int r = 0; r <= R + 1; ++r) { // each steiner point
            for (int c = 0; c <= C + 1; ++c) {
                int curr = dist[0][r][c] + dist[1][r][c] + dist[2][r][c] - 2 * (grid[r][c] == '#');
                ans = min(ans, curr);
            }
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}