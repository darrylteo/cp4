#include <bits/stdc++.h>

using namespace std;

int n, i1, i2;
double d[200][200], memo[200][200][2][2];
vector<int> forwardPath, backwardPath;

// run up to v since we have to consider all nodes before v
double dp(int p1, int p2, int i1LR, int i2LR) { // is i1 and i2 on LR path?
    int v = 1 + max(p1, p2); // this single line speeds up Bitonic TSP solution
    if (v == n - 1) {
        if (i1LR == i2LR) return 1e9; // both are on the same path NOT ALLOWED
        return d[p1][v] + d[v][p2];
    }
    if (memo[p1][p2][i1LR][i2LR] > -0.5) return memo[p1][p2][i1LR][i2LR];
    return memo[p1][p2][i1LR][i2LR] = min(
            // extend LR path: p1->v, RL stays: p2. also mark when v is i1 or i2 since we are using LR path here
            d[p1][v] + dp(v, p2, max(i1LR, (int) (v == i1)), max(i2LR, (int) (v == i2))),
            d[v][p2] + dp(p1, v, i1LR, i2LR)); // extend RL path: p2->v, LR stays: p1
}

void getSoln(int p1, int p2, int i1LR, int i2LR) {
    int v = 1 + max(p1, p2);
    if (v == n - 1) {
        forwardPath.push_back(p1);
        backwardPath.push_back(p2);
        return;
    }
    double opt = dp(p1, p2, i1LR, i2LR);
    if (d[p1][v] + dp(v, p2, max(i1LR, (int) (v == i1)), max(i2LR, (int) (v == i2))) == opt) {
        forwardPath.push_back(p1); // extend LR path: p1->v
        getSoln(v, p2, max(i1LR, (int) (v == i1)), max(i2LR, (int) (v == i2)));
    } else {
        backwardPath.push_back(p2);
        getSoln(p1, v, i1LR, i2LR);
    }
}

// dp from book. straightforward extension of BITONIC TSP

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 1;
    while (cin >> n >> i1 >> i2, n) {
        forwardPath.clear();
        backwardPath.clear();
        memset(memo, -1, sizeof memo);
        vector<pair<double, double>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = d[j][i] = hypot(a[i].first - a[j].first, a[i].second - a[j].second);
        cout << "Case " << cases++ << ": " << fixed << setprecision(2) << dp(0, 0, 0, 0) << endl;
        getSoln(0, 0, 0, 0);
        vector<int> ans;
        for (int i: forwardPath) ans.push_back(i);
        ans.push_back(n - 1);
        for (int i = backwardPath.size() - 1; i >= 0; i--) ans.push_back(backwardPath[i]);
        if (ans[1] != 1) reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}