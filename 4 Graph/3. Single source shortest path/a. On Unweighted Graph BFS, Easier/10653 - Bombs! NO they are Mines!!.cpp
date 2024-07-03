#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but shortcuts are useful in competitive programming

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1}; // S, E, N, W

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    while (cin >> R >> C, R) {
        int B;
        cin >> B;
        vector<vector<int>> grid(R, vector<int>(C, 1e9));
        for (int i = 0; i < B; i++) {
            int r, c, cnt;
            cin >> r;
            cin >> cnt;
            for (int j = 0; j < cnt; j++) {
                cin >> c;
                grid[r][c] = -1;
            }
        }
        queue<ii> q; // (row, column)
        int sr, sc, tr, tc;
        cin >> sr >> sc >> tr >> tc;
        q.push({sr, sc});
        grid[sr][sc] = 0;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = u.first + dr[i];
                int c = u.second + dc[i];
                if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] == 1e9) { // go to valid and not visited and not bomb cell
                    grid[r][c] = grid[u.first][u.second] + 1;
                    q.push({r, c});
                }
            }
        }
        cout << grid[tr][tc] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}