#include <bits/stdc++.h>

using namespace std;

const int dirr[] = {0, 1, 0, -1};
const int dirc[] = {1, 0, -1, 0};
int grid[4][4];
vector<pair<int, int>> startt(4, {-1, -1}), endd(4, {-1, -1});
int memo[4][4][1 << 16];
int id = 1; // iteration id instead of -1 since memo is fairly large

int dp(int r, int c, int mask, int color) {
    if (r == endd[color].first && c == endd[color].second) return __builtin_popcount(mask); // reached the end point
    int &ret = memo[r][c][mask];
    if (ret == id) return memo[r][c][mask];
    memo[r][c][mask] = id;
    ret = 0;
    // go to all 4 directions and try to reach end while maximizing path length
    for (int i = 0; i < 4; i++) {
        int nr = r + dirr[i], nc = c + dirc[i];
        if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
        if (grid[nr][nc] != color) continue; // not the same color (R=0, G=1, B=2, Y=3, W=4)
        if (mask & (1 << (nr * 4 + nc))) continue; // already visited
        ret = max(ret, dp(nr, nc, mask | (1 << (nr * 4 + nc)), color));
    }
    return ret;
}

bool ok() { // based on current coloring, check if valid. modify grid as global variable later
    int total = 0;
    for (auto &i: startt) {
        id++;
        int r = i.first, c = i.second;
        int curr = dp(r, c, 1 << (r * 4 + c), grid[r][c]);
        if (!curr) return false;
        total += curr;
    }
    return total == 16;
}

bool solve(int cnt) { // count the number of squares considered. if white, color. if not, skip
    if (cnt == 16) return ok();
    int r = cnt / 4, c = cnt % 4;
    if (grid[r][c] == 4) {
        for (int k = 0; k < startt.size(); k++) { // try all colors
            grid[r][c] = k;
            if (solve(cnt + 1)) return true;
            grid[r][c] = 4;
        }
        return false;
    }
    return solve(cnt + 1);
}

// general idea. 3^10 and 4^8 refer to the ways u can color the remaining squares
// so we try all these colorings, connect start to end point with the longest path of the same color
// count the squares that are colored for each color. if the sum == 16, then we have a valid coloring
// we can also use a bitmask to represent the coloring of the squares
// idk why so tedious for medium question

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 4; j++) {
            if (s[j] == 'R') grid[i][j] = 0;
            else if (s[j] == 'G') grid[i][j] = 1;
            else if (s[j] == 'B') grid[i][j] = 2;
            else if (s[j] == 'Y') grid[i][j] = 3;
            else grid[i][j] = 4;
            if (grid[i][j] != 4) { // not white
                if (startt[grid[i][j]].first == -1) startt[grid[i][j]] = {i, j};
                else endd[grid[i][j]] = {i, j};
            }
        }
    }
    if (startt[3].first == -1) { // no yellow today
        startt.pop_back();
        endd.pop_back();
    }
    cout << (solve(0) ? "solvable" : "not solvable") << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}