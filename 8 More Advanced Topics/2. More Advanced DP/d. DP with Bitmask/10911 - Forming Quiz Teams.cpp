#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

int N;
double dist[20][20], memo[1 << 16];

double dp(int mask) {
    double &ans = memo[mask];
    if (ans > -0.5) return ans;
    if (mask ==0) return 0;
    ans = 1e9;
    int two_pow_p1 = LSOne(mask);
    int p1 = __builtin_ctz(two_pow_p1);
    int m = mask-two_pow_p1;
    while (m) {
        int two_pow_p2 = LSOne(m);
        int p2 = __builtin_ctz(two_pow_p2);
        ans = min(ans, dist[p1][p2] + dp(mask^two_pow_p1^two_pow_p2));
        m -= two_pow_p2;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    int caseNo = 0, x[20], y[20];
    while (scanf("%d", &N), N) {
        for (int i = 0; i < 2*N; ++i)
            scanf("%*s %d %d", &x[i], &y[i]);
        for (int i = 0; i < 2*N-1; ++i)
            for (int j = i+1; j < 2*N; ++j)
                dist[i][j] = dist[j][i] = hypot(x[i]-x[j], y[i]-y[j]);
        for (int i = 0; i < (1<<16); ++i) memo[i] = -1.0;
        printf("Case %d: %.2lf\n", ++caseNo, dp((1<<(2*N)) - 1));
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}