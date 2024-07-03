#include <bits/stdc++.h>

using namespace std;

const int dirr8[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dirc8[] = {1, -1, 0, 0, 1, -1, 1, -1};

int R, C;
vector<vector<int>> grid;

int getDist(int r, int c) {
    int total = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int dist = abs(r - i) + abs(c - j);
            total += dist * grid[i][j];
        }
    }
    return total;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> C >> R;
        grid.resize(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }
        int x = 0, y = 0; // starting point
        int best = getDist(x, y);
        while (true) {
            bool found = false;
            for (int i = 0; i < 8; i++) {
                int nx = x + dirr8[i];
                int ny = y + dirc8[i];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                    int dist = getDist(nx, ny);
                    if (dist < best) {
                        best = dist;
                        x = nx;
                        y = ny;
                        found = true;
                    }
                }
            }
            if (!found) break;
        }
        cout << best << " blocks\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
