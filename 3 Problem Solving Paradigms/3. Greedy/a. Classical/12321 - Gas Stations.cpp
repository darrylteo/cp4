#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, G;
    while (cin >> L >> G, L || G) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i < G; ++i) {
            int x, r;
            cin >> x >> r;
            intervals.emplace_back(x - r, x + r);
        }
        sort(intervals.begin(), intervals.end());

        int covered = 0, idx = 0, ans = 0;
        while (covered < L && idx < G) {
            int max_right = -1;
            while (idx < G && intervals[idx].first <= covered) {
                max_right = max(max_right, intervals[idx].second);
                ++idx;
            }
            if (max_right == -1) {
                break;
            }
            ++ans;
            covered = max_right;
        }
        if (covered < L) {
            cout << -1 << '\n';
        } else {
            cout << G - ans << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
