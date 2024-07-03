#include <bits/stdc++.h>

using namespace std;

// okay for a hard rated qn

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (auto &i: v) cin >> i.first >> i.second;
    // finish asap so waste less time i.e. assign better activities 1st
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    map<int, int> covered;
    covered[0] = k; // k classrooms available at time 0
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int start = v[i].first, end = v[i].second;
        // find latest time that is later than start
        auto it = covered.upper_bound(-start);
        // if no such time exists, then no classroom available
        if (it == covered.end()) { // hard to debug this... but finally i know if end it shows in debug as first = covered.size() and second = 0
            continue;
        }
        // if time exists, then assign classroom
        covered[it->first]--; // reduce count of classrooms available at that time
        if (covered[it->first] == 0) {
            covered.erase(it->first);
        }
        // assign classroom at end time
        covered[-end]++;
        ans++;
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


// extra note: i did the "normal way" but it was TLE since n and k up to 200k
// normal way here:
/*
    for (int i = 0; i < n; ++i) {
        int start = v[i].first, end = v[i].second;
        int bestClass = -1, latest = -1;
        // find classroom with latest available time (so less time wasted)
        for (int j = 0; j < k; j++) {
            if (covered[j] < start) { // available
                if (covered[j] > latest) { // waste less time
                    latest = covered[j];
                    bestClass = j;
                }
            }
        }
        // assign this interval to that classroom if possible
        if (bestClass != -1) {
            covered[bestClass] = end;
            ans++;
        }
    }
*/
