#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int cases = 1; cases <= n; ++cases) {
        cout << "Case #" << cases << ":\n";
        int L, R, S;
        cin >> L >> R >> S;
        unordered_set<int> LL, RR, SS;
        for (int i = 0; i < L; ++i) {
            int x;
            cin >> x;
            LL.insert(x);
        }
        for (int i = 0; i < R; ++i) {
            int x;
            cin >> x;
            RR.insert(x);
        }
        for (int i = 0; i < S; ++i) {
            int x;
            cin >> x;
            SS.insert(x);
        }

        int ans1 = 0, ans2 = 0;
        unordered_set<int> tmp;
        // check what L has and others don't have
        for (auto x : LL) {
            if (RR.find(x) == RR.end() && SS.find(x) == SS.end()) {
                ans1++;
            }
        }
        // check what R have and L don't have
        for (auto x : RR) {
            if (LL.find(x) == LL.end()) {
                tmp.insert(x);
            }
        }
        // from this set see if S also had it (the thing that L didn't have)
        for (auto x : SS) {
            if (tmp.find(x) != tmp.end()) {
                ans2++;
            }
        }
        cout << ans1 << " " << ans2 << "\n";

        ans1 = 0, ans2 = 0;
        tmp.clear();
        for (auto x : RR) {
            if (LL.find(x) == LL.end() && SS.find(x) == SS.end()) {
                ans1++;
            }
        }
        for (auto x : LL) {
            if (RR.find(x) == RR.end()) {
                tmp.insert(x);
            }
        }
        for (auto x : SS) {
            if (tmp.find(x) != tmp.end()) {
                ans2++;
            }
        }
        cout << ans1 << " " << ans2 << "\n";

        ans1 = 0, ans2 = 0;
        tmp.clear();
        for (auto x : SS) {
            if (LL.find(x) == LL.end() && RR.find(x) == RR.end()) {
                ans1++;
            }
        }
        for (auto x : LL) {
            if (SS.find(x) == SS.end()) {
                tmp.insert(x);
            }
        }
        for (auto x : RR) {
            if (tmp.find(x) != tmp.end()) {
                ans2++;
            }
        }
        cout << ans1 << " " << ans2 << "\n";

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

