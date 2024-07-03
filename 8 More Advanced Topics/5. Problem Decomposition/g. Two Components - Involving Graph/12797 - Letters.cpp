#include <bits/stdc++.h>

using namespace std;

const int dirr[] = {0, 1, 0, -1};
const int dirc[] = {1, 0, -1, 0};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        vector<string> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        int x = 0, y = 0, best = 1e9;
        // 0 bits mean step on small letter, 1 bits mean step on capital letter
        for (int mask = 0; mask < (1 << 10) - 1; ++mask) {
            if (isupper(v[x][y]) && (mask & (1 << (v[x][y] - 'A'))) == 0) continue; // capital letter but 0 in mask
            if (islower(v[x][y]) && (mask & (1 << (v[x][y] - 'a')))) continue; // small letter but 0 in mask

            queue<pair<int, int>> q;
            vector<vector<int>> dist(N, vector<int>(N, 1e9));
            q.emplace(x, y);
            dist[x][y] = 0;
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dirr[i], nc = c + dirc[i];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                    if (isupper(v[nr][nc]) && (mask & (1 << (v[nr][nc] - 'A'))) == 0) continue;
                    if (islower(v[nr][nc]) && (mask & (1 << (v[nr][nc] - 'a')))) continue;
                    if (dist[nr][nc] == 1e9) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.emplace(nr, nc);
                    }
                }
            }
            best = min(best, dist[N - 1][N - 1]);
        }
        if (best == 1e9) cout << -1 << endl;
        else cout << best + 1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}