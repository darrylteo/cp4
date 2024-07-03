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

    int r;
    cin >> r;
    vector<string> board(r);
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }
    int sr, sc;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (board[i][j] == 'K') {
                sr = i;
                sc = j;
                break;
            }
        }
    }
    vector<vi> dist(r, vi(r, -1));
    queue<ii> q;
    q.push({sr, sc});
    dist[sr][sc] = 0;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nr = u.first + drK[i];
            int nc = u.second + dcK[i];
            if (nr >= 0 && nr < r && nc >= 0 && nc < r && board[nr][nc] != '#' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[u.first][u.second] + 1;
                q.push({nr, nc});
            }
        }
    }
    if (dist[0][0] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[0][0] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}