#include <bits/stdc++.h>

using namespace std;

vector<double> p;
int n;
double memo[105][105];

inline double prob(int a, int s) {
    if (a < 0) return 0;
    if (a > s) return 0;
    if (a == 0 && s == 0) return 1;
    if (memo[a][s] > -0.5) return memo[a][s];
    // got accepted on current paper + didn't get accepted on current paper
    return memo[a][s] = prob(a - 1, s - 1) * p[s - 1] + prob(a, s - 1) * (1 - p[s - 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] /= 100;
    }
    sort(p.begin(), p.end(), greater<double>());
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            memo[i][j] = -1;
    double ans = 0;
    for (int s = 1; s <= n; ++s) {
        double e = 0;
        for (int a = 1; a <= s; ++a) e += prob(a, s) * pow(a, (double) a / s);
        ans = max(ans, e);
    }
    cout << fixed << setprecision(9) << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}