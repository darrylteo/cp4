#include <bits/stdc++.h>

using namespace std;

struct interval {
    int l, r;
};

// direct application from https://github.com/stevenhalim/cpbook-code/blob/master/ch3/greedy/grass_UVa10382.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << '\n';
        }
        int total, l, r;
        cin >> total;
        vector<interval> intervals;
        while (cin >> l >> r, l || r) {
            intervals.push_back({l, r});
        }
        sort(intervals.begin(), intervals.end(), [](const interval &a, const interval &b) {
            return a.l < b.l;
        });
        bool possible = true;
        int covered = 0, idx;
        vector<interval> ans;
        for (int j = 0; j < intervals.size() && possible && covered < total; ++j) {
            if (intervals[j].r <= covered) continue;
            if (intervals[j].l <= covered) {
                int mx = -1;
                for (int k = j; k < intervals.size() && intervals[k].l <= covered; ++k) {
                    if (intervals[k].r > mx) {
                        mx = intervals[k].r;
                        idx = k;
                    }
                }
                covered = mx;
                j = idx; // skip to here
                ans.push_back(intervals[idx]);
            } else {
                possible = false;
            }
        }
        if (covered < total || !possible) cout << 0 << '\n';
        else {
            cout << ans.size() << '\n';
            for (auto &x: ans) {
                cout << x.l << ' ' << x.r << '\n';
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
