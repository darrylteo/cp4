#include <bits/stdc++.h>

using namespace std;

// NESW
vector<int> dir4x = {-1, 0, 1, 0}, dir4y = {0, 1, 0, -1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, cases = 1;
    while (cin >> n >> m, n) {
        if (cases > 1) cout << '\n';
        cout << "Case #" << cases++ << '\n';
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];
        int sx, sy, tx, ty;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S') sx = i, sy = j;
                if (grid[i][j] == 'T') tx = i, ty = j;
            }
        map<tuple<int, int, int, int>, int> dist; // (x, y, dir, steps (mod 5)), dist
        queue<tuple<int, int, int, int>> q;
        q.emplace(sx, sy, 0, 0);
        dist[{sx, sy, 0, 0}] = 0;
        int found = 0;
        while (!q.empty()) {
            auto [x, y, dir, steps] = q.front();
            q.pop();
            if (x == tx && y == ty && steps == 0) {
                cout << "minimum time = " << dist[{x, y, dir, steps}] << " sec\n";
                found = 1;
                break;
            }
            // move 1 step
            int nx = x + dir4x[dir], ny = y + dir4y[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' &&
                dist.find({nx, ny, dir, (steps + 1) % 5}) == dist.end()) {
                dist[{nx, ny, dir, (steps + 1) % 5}] = dist[{x, y, dir, steps}] + 1;
                q.emplace(nx, ny, dir, (steps + 1) % 5);
            }
            // change direction 90 degrees clockwise
            int ndir = (dir + 1) % 4;
            if (dist.find({x, y, ndir, steps}) == dist.end()) {
                dist[{x, y, ndir, steps}] = dist[{x, y, dir, steps}] + 1;
                q.emplace(x, y, ndir, steps);
            }
            // change direction 90 degrees counterclockwise
            ndir = (dir + 3) % 4;
            if (dist.find({x, y, ndir, steps}) == dist.end()) {
                dist[{x, y, ndir, steps}] = dist[{x, y, dir, steps}] + 1;
                q.emplace(x, y, ndir, steps);
            }
        }
        if (!found) cout << "destination not reachable\n";
    }
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}