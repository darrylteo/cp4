#include <bits/stdc++.h>

using namespace std;

inline double dist(double r1, double r2) { // pythagorean theorem
    return sqrt((r1 + r2) * (r1 + r2) - (r1 - r2) * (r1 - r2));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<double> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        double best = 1e9;
        do {
            double worst = 0;
            // r[i] is dist where center of ball i lies
            vector<double> r(n);
            r[0] = v[0];
            for (int i = 1; i < n; i++) { // sort of bottom-up dp
                r[i] = v[i]; // at least this dist. regardless if tiny balls are to its left
                for (int j = 0; j < i; j++) {
                    r[i] = max(r[i], r[j] + dist(v[i], v[j]));
                }
            }
            // helps account for when little balls are at the end and a large ball is before and covers little balls
            for (int i = 0; i < n; i++) {
                worst = max(worst, r[i] + v[i]);
            }
            best = min(best, worst);
        } while (next_permutation(v.begin(), v.end()));
        cout << fixed << setprecision(3) << best << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
