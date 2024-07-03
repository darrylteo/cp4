#include <bits/stdc++.h>

using namespace std;

// observe image. coast is always on his right side so trying to go clockwise is favorable
// maximum he can turn is 2 units clockwise, 2 units anti-clockwise or 180 degree
// so we can just start 2 units clockwise, turn until 180. should be fine no need skip 3 units anti-clockwise

// order follows compass in figure 2
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x0, y0, d;
    while (cin >> x0 >> y0 >> d) {
        if (x0 == -1) break;
        int grid[3][3];
        int x, y, land;
        for (int i = 0; i < 8; ++i) {
            cin >> x >> y >> land;
            grid[2 - (y - y0 + 1)][x - x0 + 1] = land; // THIS QN GIVING X AND Y INSTEAD OF R AND C >:(
        }
        for (int i = 0; i < 8; ++i) {
            int dHere = (d + i + 6) % 8; // +6 = start 2 unit clockwise
            int xHere = dy[dHere] + 1; // notice the flip dydx
            int yHere = dx[dHere] + 1;
            if (grid[xHere][yHere] == 1) {
                cout << dHere << '\n';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
