#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<double> v(n), v1(n+m);
        for (int i = 1; i < n; ++i) {
            v[i] = v[i - 1] + 10000.0 / n;
        }
        for (int i = 1; i < n + m; ++i) {
            v1[i] = v1[i - 1] + 10000.0 / (n + m);
        }
        // just shift to the closest point in new equidistant points
        double ans = 0;
        for (int i = 1; i < n; ++i) {
            int pos = lower_bound(v1.begin(), v1.end(), v[i]) - v1.begin();
            if (pos == 0) {
                ans += v1[pos] - v[i];
                continue;
            }
            if (v1[pos] - v[i] < v[i] - v1[pos - 1]) {
                ans += v1[pos] - v[i];
            } else {
                ans += v[i] - v1[pos - 1];
            }
        }
        cout << fixed << setprecision(4) << ans << endl;
    }
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}