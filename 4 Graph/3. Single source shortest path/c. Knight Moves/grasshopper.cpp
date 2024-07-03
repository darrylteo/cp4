#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int drK[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dcK[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, c, sr, sc, tr, tc;
    while (cin >> r >> c >> sr >> sc >> tr >> tc) {
        --sr, --sc, --tr, --tc;
        vector<vi> dist(r, vi(c, -1));
        queue<ii> q;
        q.push({sr, sc});
        dist[sr][sc] = 0;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            if (u.first == tr && u.second == tc) break;
            for (int i = 0; i < 8; ++i) {
                int nr = u.first + drK[i];
                int nc = u.second + dcK[i];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[u.first][u.second] + 1;
                    q.push({nr, nc});
                }
            }
        }
        if (dist[tr][tc] == -1) {
            cout << "impossible" << endl;
        } else {
            cout << dist[tr][tc] << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}