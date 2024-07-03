#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int grid[2005][2005];

// straightforwad bfs, but initially using comparing each pair of block 1 and block 2 will TLE.
// bfs O(n^2) to cover whole map. compare is O(n^4) as could have (n^2)/2 points compare with (n^2)/2 points

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a1, a2;
    while (cin >> a1, a1) {
        queue<ii> q1;
        memset(grid, -1, sizeof grid);
        for (int i = 0; i < a1; i++) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 0;
            q1.emplace(x, y);
        }
        cin >> a2;
        for (int i = 0; i < a2; i++) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = -2; // end
        }

        while (!q1.empty()) {
            ii u = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int x = u.first + dx[i];
                int y = u.second + dy[i];
                if (x >= 0 && x < 2000 && y >= 0 && y < 2000) {
                    if (grid[x][y] == -1) { // not visited
                        grid[x][y] = grid[u.first][u.second] + 1;
                        q1.emplace(x, y);
                    }
                    if (grid[x][y] == -2) { // found dest
                        cout << grid[u.first][u.second] + 1 << endl;
                        while (!q1.empty()) q1.pop();
                        break;
                    }
                }
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}