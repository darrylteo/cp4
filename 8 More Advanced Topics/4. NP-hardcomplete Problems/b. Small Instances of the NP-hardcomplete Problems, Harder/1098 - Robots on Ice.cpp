#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y, t;
};
int R, C;
vector<point> v(4);
const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};
int visited[8][8];

// ref: https://mypaper.pchome.com.tw/zerojudge/post/1324932028
// if used and not used alternates too many times, invalid
int divid2(int x, int y) {
    static int vv[9], i, j;
    vv[0] = x - 1 < 0 || y - 1 < 0 || visited[x - 1][y - 1];
    vv[1] = x - 1 < 0 || visited[x - 1][y];
    vv[2] = x - 1 < 0 || y + 1 >= C || visited[x - 1][y + 1];
    vv[3] = y + 1 >= C || visited[x][y + 1];
    vv[4] = x + 1 >= R || y + 1 >= C || visited[x + 1][y + 1];
    vv[5] = x + 1 >= R || visited[x + 1][y];
    vv[6] = x + 1 >= R || y - 1 < 0 || visited[x + 1][y - 1];
    vv[7] = y - 1 < 0 || visited[x][y - 1];
    vv[8] = vv[0];
    for(i = 0, j = 0; i < 8; i++)
        if(vv[i] != vv[i + 1])
            j++;
    return j >= 4;
}

int dp(int r, int c, int time) {
    // out of bounds or visited
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (visited[r][c]) return 0;
    // visited earlier
    if (visited[v[0].x][v[0].y] && time < v[0].t || (r != v[0].x || c != v[0].y) && time == v[0].t) return 0;
    if (visited[v[1].x][v[1].y] && time < v[1].t || (r != v[1].x || c != v[1].y) && time == v[1].t) return 0;
    if (visited[v[2].x][v[2].y] && time < v[2].t || (r != v[2].x || c != v[2].y) && time == v[2].t) return 0;
    if (visited[v[3].x][v[3].y] && time < v[3].t || (r != v[3].x || c != v[3].y) && time == v[3].t) return 0;
    if (time == R * C) return 1; // success
    // check if can reach next checkpoint based on max moves
    int nextId = 0;
    for (int i = 0; i < 4; ++i) {
        if (time < v[i].t) {
            nextId = i;
            break;
        }
    }
    if (abs(r - v[nextId].x) + abs(c - v[nextId].y) > v[nextId].t - time) return 0;
    // wot
    if (divid2(r, c)) return 0;
    // go all dir
    int ans = 0;
    visited[r][c] = 1;
    for (int i = 0; i < 4; ++i) ans += dp(r + dirr[i], c + dirc[i], time + 1);
    visited[r][c] = 0;
    return ans;
}

// no way this is "entry level" qn -_-

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 1;
    while (cin >> R >> C, R) {
        v[3] = {0, 1, R * C}; // note t starts at 1 on initial square (see sample pic in qn)
        for (int i = 0; i < 3; ++i) cin >> v[i].x >> v[i].y;
        v[0].t = R * C / 4, v[1].t = R * C / 2, v[2].t = 3 * R * C / 4;
        memset(visited, 0, sizeof(visited));
        cout << "Case " << cases++ << ": " << dp(0, 0, 1) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
