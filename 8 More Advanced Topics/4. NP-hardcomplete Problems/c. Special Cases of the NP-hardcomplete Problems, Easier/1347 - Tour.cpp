#include <bits/stdc++.h>

using namespace std;

int n;
double d[200][200], memo[200][200]; // qn nvr say limits...

// run up to v since we have to consider all nodes before v
double dp(int p1, int p2) { // call dp2(0, 0)
    int v = 1 + max(p1, p2); // this single line speeds up Bitonic TSP solution
    if (v == n - 1) return d[p1][v] + d[v][p2];
    if (memo[p1][p2] > -0.5) return memo[p1][p2];
    return memo[p1][p2] = min(
            d[p1][v] + dp(v, p2), // extend LR path: p1->v, RL stays: p2
            d[v][p2] + dp(p1, v)); // LR stays: p1, extend RL path: p2<-v
}

// dp from book

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        memset(memo, -1, sizeof memo);
        vector<pair<double, double>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = d[j][i] = hypot(a[i].first - a[j].first, a[i].second - a[j].second);
        cout << fixed << setprecision(2) << dp(0, 0) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}