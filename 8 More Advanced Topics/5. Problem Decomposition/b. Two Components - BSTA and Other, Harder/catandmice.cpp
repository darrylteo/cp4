#include <bits/stdc++.h>

using namespace std;

int n;
double dist[16][16], memo[1 << 16][16], latest[16], pows[16], distToFirst[16];
double fac, spd;

bool ok() {
    for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < n; ++j) memo[i][j] = 1e9;
    for (int i = 0; i < n; ++i) {
        double time = distToFirst[i] / spd;
        if (time <= latest[i]) memo[1 << i][i] = time;
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; ++j) {
                    double newSpd = spd * pows[__builtin_popcount(mask)];
                    if (!(mask & (1 << j)) && memo[mask][i] + dist[i][j] / newSpd <= latest[j]) {
                        memo[mask | (1 << j)][j] = min(memo[mask | (1 << j)][j], memo[mask][i] + dist[i][j] / newSpd);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (memo[(1 << n) - 1][i] <= latest[i]) return true;
    }
    return false;
}

// ref: https://www.cnblogs.com/letlifestop/p/11064920.html
// wow bottom up tsp. pretty cool

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    vector<pair<double, double>> coord(n);
    for (int i = 0; i < n; ++i) cin >> coord[i].first >> coord[i].second >> latest[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dist[i][j] = dist[j][i] = hypot(coord[i].first - coord[j].first, coord[i].second - coord[j].second);
        }
    }
    for (int i = 0; i < n; ++i) distToFirst[i] = hypot(coord[i].first, coord[i].second);
    cin >> fac;
    for (int i = 0; i <= n; ++i) pows[i] = pow(fac, i);
    double l = 0, r = 1e9;
    while (abs(r - l) > 1e-6) {
        spd = (l + r) / 2;
        if (ok()) r = spd;
        else l = spd;
    }
    cout << fixed << setprecision(6) << l << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
