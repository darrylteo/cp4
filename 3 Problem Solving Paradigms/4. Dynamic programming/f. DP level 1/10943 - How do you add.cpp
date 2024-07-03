#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int i, j, split, dp[110][110], N, K;

    memset(dp, 0, sizeof dp);

    for (i = 0; i <= 100; i++) // these are the base cases
        dp[i][1] = 1;

    for (j = 1; j < 100; j++) // these three nested loops form the correct topological order
        for (i = 0; i <= 100; i++)
            for (split = 0; split <= 100 - i; split++) {
                dp[i + split][j + 1] += dp[i][j];
                dp[i + split][j + 1] %= 1000000;
            }

    while (scanf("%d %d", &N, &K), (N || K))
        printf("%d\n", dp[N][K]);

    return 0;
}