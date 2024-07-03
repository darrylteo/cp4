#include <bits/stdc++.h>

using namespace std;

// ref: https://blog.csdn.net/acm_lkl/article/details/46492027

// dp stores best cost given i depots, up to restaurant j
// dist is just the restaurant distances
// cost is cheapest cost to build 1 depot to handle restaurant i to j
int dp[35][205], dist[205], cost[205][205], n, k, chain = 0;

void print(int i, int j) {
    if (i == 1) {
        if (j == 1) {
            cout << "Depot " << i << " at restaurant " << i << " serves restaurant " << j << endl;
            return;
        } else {
            cout << "Depot " << i << " at restaurant " << (i + j) / 2 << " serves restaurants " << 1 << " to " << j
                 << endl;
            return;
        }
    } else {
        for (int d = i - 1; d < j; ++d) {
            if (dp[i][j] == dp[i - 1][d] + cost[d + 1][j]) {
                print(i - 1, d);
                if (d + 1 == j) {
                    cout << "Depot " << i << " at restaurant " << (d + 1 + j) / 2 << " serves restaurant " << d + 1
                         << endl;
                    return;
                } else {
                    cout << "Depot " << i << " at restaurant " << (d + 1 + j) / 2 << " serves restaurants " << d + 1
                         << " to " << j << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> n >> k, n) {
        for (int i = 1; i <= n; ++i) {
            cin >> dist[i];
        }
        // we get the cost 1st. always place depot at mid point of i and j, then add all distances to this mid point.
        memset(cost, 0, sizeof(cost));
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int mid = (i + j) / 2;
                for (int d = i; d <= j; ++d) {
                    cost[i][j] += abs(dist[d] - dist[mid]);
                }
            }
        }
        // just setting to inf since we finding min dist
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = 1e9;
            }
        }
        // base case
        for (int i = 1; i <= n; ++i) {
            dp[1][i] = cost[1][i];
        }
        // dp
        for (int i = 2; i <= k; ++i) { // for no. of depot
            for (int j = i; j <= n; ++j) { // for no. of restaurants
                for (int d = i - 1; d < j; ++d) { // check best depot to add to handle restaurants from d + 1 to j
                    // 1 less depot handle to d + best cost to handle d + 1 to j. best cost from previous step
                    dp[i][j] = min(dp[i][j], dp[i - 1][d] + cost[d + 1][j]);
                }
            }
        }
        cout << "Chain " << ++chain << endl;
        print(k, n);
        cout << "Total distance sum = " << dp[k][n] << endl << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


