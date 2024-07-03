#include <bits/stdc++.h>

using namespace std;

struct range{
    double l, r;
};

// follow book clue, sort by ranges and greedy linear pass

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<range> ranges(n);
        for (int i = 0; i < n; ++i) {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            double a1 = atan2(y1, x1);
            double a2 = atan2(y2, x2);
            ranges[i] = {min(a1, a2), max(a1, a2)};
        }
        int cnt = 0;
        double cur = -M_PI;
        sort(ranges.begin(), ranges.end(), [](const range &a, const range &b) {
            return a.l < b.l;
        });
        for (int i = 0; i < n; ++i) {
            if (ranges[i].l > cur) {
                cnt++;
                cur = ranges[i].r;
            } else {
                cur = min(cur, ranges[i].r);
            }
        }
        cout << cnt << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
