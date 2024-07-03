#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char g[4][4];
int dp[65536], used[65536];

inline int dfs(int state) {
    if (state == 65535) return 1; // the other guy insert the last pin
    if (used[state]) return dp[state]; // already calculated
    int &ret = dp[state];
    used[state] = 1;
    ret = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((state >> (i * 4 + j)) & 1) continue; // if cell is occupied
            ret |= !dfs(state | (1 << (i * 4 + j))); // insert from top occupying just 1 square
            if (ret) return ret;
            for (int k = 0; k < 4; k++) {
                int x = i, y = j, pin = 0;
                if (x - dx[k] >= 0 && x - dx[k] < 4 && y - dy[k] >= 0 && y - dy[k] < 4)
                    continue; // not at edge or at edge but wrong direction
                for (int l = 0; l < 3; l++) {
                    pin |= 1 << (x*4+y);
                    ret |= !dfs(state | pin); // insert from some side occupying l squares.
                    if (ret) return ret;
                    x += dx[k], y += dy[k];
                    if ((state >> (x * 4 + y)) & 1) break; // if cell is occupied, can't poke pin any further
                }
            }
        }
    }
    return ret;
}

// ref: https://mypaper.pchome.com.tw/zerojudge/post/1325328905

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 4; i++) {
            cin >> g[i];
        }
        int state = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (g[i][j] == 'X') state |= 1 << (i * 4 + j);
            }
        }
        if (dfs(state)) cout << "WINNING" << endl;
        else cout << "LOSING" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

