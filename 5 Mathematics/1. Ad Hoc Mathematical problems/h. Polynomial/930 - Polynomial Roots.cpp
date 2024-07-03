#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;

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
        n++;
        vector<double> line1(n), line2(n - 1), line3(n - 1);
        for (int i = 0; i < n; i++) cin >> line1[i];
        for (int i = 0; i < n - 3; ++i) {
            double root;
            cin >> root;
            line3[0] = line1[0];
            int opsCnt = line1.size() - 2;
            for (int j = 0; j < opsCnt; ++j) {
                line2[j + 1] = line3[j] * root;
                line3[j + 1] = line1[j + 1] + line2[j + 1];
            }
            line1 = line3;
        }
        // you got ur 3 coefficients in line1 now. just print res.
        double ans1 = (-line1[1] + sqrt(line1[1] * line1[1] - 4 * line1[0] * line1[2])) / (2 * line1[0]);
        double ans2 = (-line1[1] - sqrt(line1[1] * line1[1] - 4 * line1[0] * line1[2])) / (2 * line1[0]);
        cout << fixed << setprecision(1) << ans1 << '\n' << ans2 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

