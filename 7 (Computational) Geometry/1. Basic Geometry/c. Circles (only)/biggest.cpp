#include <bits/stdc++.h>

using namespace std;

bitset<60 * 60 * 360> cuts;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cuts = 0;
        int r, n, t1, t2, t3, theta;
        cin >> r >> n >> t1 >> t2 >> t3;
        theta = 60 * 60 * t1 + 60 * t2 + t3;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (cuts[curr]) break; // IMPORTANT. it will cycle anyway
            cuts[curr] = true;
            curr += theta;
            if (curr >= 60 * 60 * 360) curr -= 60 * 60 * 360;
        }
        int longest = 0, curr_len = 0;
        for (int i = 0; i < 60 * 60 * 360; ++i) {
            if (cuts[i]) {
                longest = max(longest, curr_len);
                curr_len = 1;
            } else {
                curr_len++;
            }
        }
        double best = max(longest, curr_len) / 3600.0;
        cout << fixed << setprecision(10) << M_PI * r * r * best / 360 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}