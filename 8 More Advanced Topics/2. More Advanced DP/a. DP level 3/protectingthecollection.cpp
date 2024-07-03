#include <bits/stdc++.h>

using namespace std;

enum {
    NORTH, EAST, SOUTH, WEST
};

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};

int newDir(int dir, char c) {
    if (c == '/') {
        if (dir == NORTH) return EAST;
        if (dir == EAST) return NORTH;
        if (dir == SOUTH) return WEST;
        if (dir == WEST) return SOUTH;
    } else {
        if (dir == NORTH) return WEST;
        if (dir == EAST) return SOUTH;
        if (dir == SOUTH) return EAST;
        if (dir == WEST) return NORTH;
    }
    return 0; // should never reach here
}

int memo[2005][2005][4][2]; // x, y, dir, mirror used
char grid[2005][2005];
int n, laserCol, sensorRow;

int dp(int x, int y, int dir, bool mirror) {
    if (x == sensorRow && y == n) return 1; // imagine must +1 EAST to sensor
    if (x < 0 || x >= n || y < 0 || y >= n) return 0;
    int &res = memo[x][y][dir][mirror];
    if (res != -1) return res;
    if (grid[x][y] != '.') {
        int newDr = newDir(dir, grid[x][y]);
        return res = dp(x + dirx[newDr], y + diry[newDr], newDr, mirror);
    }
    if (mirror) {
        int newDr1 = newDir(dir, '/'), newDr2 = newDir(dir, '\\');
        return res = dp(x + dirx[dir], y + diry[dir], dir, mirror) || // did not use mirror
                     dp(x + dirx[newDr1], y + diry[newDr1], newDr1, false) || // used mirror
                     dp(x + dirx[newDr2], y + diry[newDr2], newDr2, false); // used mirror
    } else {
        return res = dp(x + dirx[dir], y + diry[dir], dir, mirror);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> laserCol >> sensorRow;
    laserCol--;
    sensorRow--;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
    memset(memo, -1, sizeof(memo));
    cout << (dp(0, laserCol, SOUTH, true) ? "YES" : "NO") << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
