#include <bits/stdc++.h>

using namespace std;

// https://mypaper.pchome.com.tw/zerojudge/post/1325783310
// not sure how to solve... code from link

int g[2010][2010], dp[2010][2010];
int lx[4010], rx[4010], ly[4010], ry[4010];
long long x[4010], y[4010];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    int m, n, w;
    int i, j, p;
    while (cin >> m >> n >> w && m) {
        map<int, int> Rx, Ry;
        Rx[0] = 1, Ry[0] = 1;
        Rx[n] = 1, Ry[m] = 1; // so that in dp later we start outside the map (1 step NE of exit)
        for (i = 0; i < w; i++) {
            cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
            rx[i]++, ry[i]++;
            Rx[lx[i]] = 1, Ry[ly[i]] = 1;
            Rx[rx[i]] = 1, Ry[ry[i]] = 1;
        }
        // x holds the sorted x coordinates. and their index in Rx. same for y
        int sizex = 0, sizey = 0;
        for (auto &it: Rx) {
            it.second = sizex;
            x[sizex++] = it.first;
        }
        for (auto &it: Ry) {
            it.second = sizey;
            y[sizey++] = it.first;
        }
        memset(g, 0, sizeof(g));
        memset(dp, 0, sizeof(dp));
        for (i = 0; i < w; i++) {
            int llx = Rx[lx[i]], rrx = Rx[rx[i]]; // id start and id end of x
            int rry = Ry[ry[i]];
            for (p = llx + 1; p <= rrx; p++) g[p][rry] = 1; // wall block
        }
        dp[sizex - 1][sizey - 1] = 1;
        long long ret = 0;
        // start from exit, move SW
        for (i = sizex - 1; i > 0; i--) {
            for (j = sizey - 1; j > 0; j--) {
                if (g[i][j]) continue;
                if (!dp[i][j]) ret += (x[i] - x[i - 1]) * (y[j] - y[j - 1]);
                dp[i - 1][j] |= dp[i][j];
                dp[i][j - 1] |= dp[i][j];
            }
        }
        cout << "Case " << ++cases << ": " << ret << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}