#include <bits/stdc++.h>

using namespace std;

// similar to 1193 - Radar Installation. recycled code

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y};
    }
    sort(ranges.begin(), ranges.end());
    int radarCount = 1;
    int right = ranges[0].second; // furthest u can put current radar
    for (int i = 1; i < n; i++) {
        if (ranges[i].first > right) {
            radarCount++;
            right = ranges[i].second;
        } else {
            right = min(right, ranges[i].second);
        }
    }
    cout << radarCount << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
