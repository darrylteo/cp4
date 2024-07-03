#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<iii> viii;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

// seems like must do once with no obstacles, then do with obstacles

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m >> ws;
        vvi grid(n, vi(m, 0)), gridNoObstacles(n, vi(m, 0)); // 0 is ok, 1 is bad
        for (int i = 0; i < n; i++) {
            string buf;
            int x;
            getline(cin, buf);
            stringstream ss(buf);
            ss >> x; // 1st digit nothing
            while (ss >> x) {
                grid[i][x - 1] = 1;
            }
        }

        vvi distNoObstacles(n, vi(m, 1e9));
        distNoObstacles[0][0] = 0;
        // original Dijkstra's algorithm
        set<iii> pqNoObstacles;
        pqNoObstacles.insert({0, 0, 0});
        while (!pqNoObstacles.empty()) {
            auto [d, r, c] = *pqNoObstacles.begin();
            pqNoObstacles.erase(pqNoObstacles.begin());
            if (d > distNoObstacles[r][c]) continue;
            for (int j = 0; j < 4; j++) {
                int nr = r + dr[j], nc = c + dc[j];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (distNoObstacles[r][c] + 1 > distNoObstacles[nr][nc]) continue;        // worse
                pqNoObstacles.erase({distNoObstacles[nr][nc], nr, nc});                     // erase old pair
                distNoObstacles[nr][nc] = distNoObstacles[r][c] + 1;                       // relax operation
                pqNoObstacles.insert({distNoObstacles[nr][nc], nr, nc});                     // update the pair
            }
        }


        vvi dist(n, vi(m, 1e9));
        dist[0][0] = 0;
        vvi parentCnt(n, vi(m, 0));
        parentCnt[0][0] = 1;

        // original Dijkstra's algorithm
        set<iii> pq;
        pq.insert({0, 0, 0});

        // sort the pairs by non-decreasing distance from s
        while (!pq.empty()) {                          // main loop
            auto [d, r, c] = *pq.begin();
            pq.erase(pq.begin());
            if (d > dist[r][c]) continue;               // a very important check
            for (int j = 0; j < 4; j++) {
                int nr = r + dr[j], nc = c + dc[j];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (grid[nr][nc] == 1) continue;
                if (dist[r][c] + 1 > dist[nr][nc]) continue;        // worse
                if (dist[r][c] + 1 == dist[nr][nc]) {
                    parentCnt[nr][nc] += parentCnt[r][c];
                } else {
                    pq.erase({dist[nr][nc], nr, nc});                     // erase old pair
                    dist[nr][nc] = dist[r][c] + 1;                       // relax operation
                    pq.insert({dist[nr][nc], nr, nc});                     // update the pair
                    parentCnt[nr][nc] = parentCnt[r][c];
                }
            }
        }

        if (distNoObstacles[n - 1][m - 1] < dist[n - 1][m - 1]) {
            cout << 0 << endl;
        } else {
            cout << parentCnt[n - 1][m - 1] << endl;
        }
        if (T) cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}