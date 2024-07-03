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
    bool found = false;
    unordered_map<int, int> curr, minDist, cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
        if (cnt[x] > 1) {
            found = true;
            minDist[x] = INT_MAX;
        }
        if (curr.find(x) != curr.end()) {
            minDist[x] = min(minDist[x], i - curr[x]);
        }
        curr[x] = i;
    }
    if (!found) {
        cout << n << endl;
    } else {
        int ans = INT_MAX;
        for (auto &p : minDist) {
            ans = min(ans, p.second);
        }
        cout << ans << endl;
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
