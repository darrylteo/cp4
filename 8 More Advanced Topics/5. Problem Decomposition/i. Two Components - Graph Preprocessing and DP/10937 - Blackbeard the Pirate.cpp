#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & (-S))

const int dirr4[] = {0, 1, 0, -1};
const int dirc4[] = {1, 0, -1, 0};
const int dirr8[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dirc8[] = {1, 0, -1, 0, 1, 1, -1, -1};

struct point {
    int r, c;
};

vector<vector<int>> dist;
vector<vector<int>> memo;

// what is the minimum cost if we are at vertex u and have visited vertices
// that are described by the off (0 bit) in mask?
int dp(int u, int mask) { // mask = free coordinates
    if (mask == 0) return dist[u][0]; // close the tour
    int &ans = memo[u][mask];
    if (ans != -1) return ans; // computed before
    ans = 2000000000;
    int m = mask;
    while (m) { // up to O(n)
        int two_pow_v = LSOne(m); // but this is fast
        int v = __builtin_ctz(two_pow_v); // offset v by +1
        ans = min(ans, dist[u][v] + dp(v, mask^two_pow_v)); // keep the min
        m -= two_pow_v;
    }
    return ans;
}

// follow book.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    while (cin >> R >> C, R) {
        vector<string> grid(R);
        for (int i = 0; i < R; i++) cin >> grid[i];
        // find angry natives and block this path
        int reachable = 1;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == '*') {
                    for (int i = 0; i < 8; i++) {
                        int nr = r + dirr8[i];
                        int nc = c + dirc8[i];
                        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                            if (grid[nr][nc] == '.') grid[nr][nc] = 'X';
                            if (grid[nr][nc] == '!' || grid[nr][nc] == '@') reachable = 0;
                        }
                    }
                }
            }
        }
        if (!reachable) { // lame corner cases -_- the natives might attack the boat or treasure before even starting
            cout << -1 << endl;
            continue;
        }
        vector<point> points;
        int id = 1; // all treasures labeled by id. starting is 0 (his boat)
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == '!') {
                    if (id == 10) grid[r][c] = 'A'; // can't fit 10 in one char
                    else grid[r][c] = to_string(id++)[0];
                    points.push_back({r, c});
                }
                if (grid[r][c] == '@') {
                    grid[r][c] = '0';
                    points.insert(points.begin(), {r, c});
                }
            }
        }


        // bfs from each point to all other points
        dist.assign(points.size(), vector<int>(points.size(), -1));
        for (int i = 0; i < points.size() && reachable; i++) {
            vector<vector<int>> d(R, vector<int>(C, -1));
            queue<point> q;
            q.push(points[i]);
            d[points[i].r][points[i].c] = 0;
            while (!q.empty()) {
                point p = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nr = p.r + dirr4[j];
                    int nc = p.c + dirc4[j];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != 'X' && grid[nr][nc] != '#' && grid[nr][nc] != '~' && d[nr][nc] == -1) {
                        d[nr][nc] = d[p.r][p.c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
            for (int j = 0; j < points.size(); j++) {
                dist[i][j] = d[points[j].r][points[j].c];
                if (dist[i][j] == -1) {
                    reachable = 0;
                    break;
                }
            }
        }
        if (!reachable) {
            cout << -1 << endl;
            continue;
        }

        // TSP
        memo.assign(points.size(), vector<int>(1 << points.size(), -1));
        cout << dp(0, (1 << points.size()) - 2) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
