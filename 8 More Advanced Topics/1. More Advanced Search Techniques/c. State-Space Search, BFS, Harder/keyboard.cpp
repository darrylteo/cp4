#include <bits/stdc++.h>

using namespace std;

vector<int> dirr = {0, 0, 1, -1};
vector<int> dirc = {1, -1, 0, 0};
int dist[50][50][10005];

// MLE when using string. use num of correct chars pressed instead
// TLE when using unordered_map. use array instead
// lols just nice AC... 2.92s/3.00s

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    string correct;
    cin >> correct;
    correct += '*';
    int correctSz = (int) correct.size();
    int x = 0, y = 0; // starting pos
    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> q;
    q.emplace(x, y, 0);
    dist[x][y][0] = 0;
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        auto [x, y, num] = q.front();
        q.pop();
        if (num == correctSz) {
            cout << dist[x][y][num] << '\n';
            break;
        }
        char cur = grid[x][y];
        // press
        if (correct[num] == cur && dist[x][y][num + 1] == -1) {
            dist[x][y][num+1] = dist[x][y][num] + 1;
            q.emplace(x, y, num + 1);
        }
        // movement is funky cuz sometimes it will skip letters
        for (int i = 0; i < 4; i++) {
            int oki = 0, nx = x, ny = y;
            while (true) {
                nx += dirr[i];
                ny += dirc[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) break; // bad. same letter all the way to grid boundary
                if (grid[nx][ny] != cur) {
                    oki = 1;
                    break;
                }
            }
            if (!oki) continue;
            if (dist[nx][ny][num] == -1) {
                dist[nx][ny][num] = dist[x][y][num] + 1;
                q.emplace(nx, ny, num);
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}