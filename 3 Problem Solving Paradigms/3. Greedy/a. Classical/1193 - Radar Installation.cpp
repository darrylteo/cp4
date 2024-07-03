#include <bits/stdc++.h>

using namespace std;

// in sprinkler qn, we find range of each sprinkler and decide to use or not
// here we find range of each island and set radars to cover all islands
// we can place a radar to left or right of island and reach it if r^2 >= (x_radar - x_island)^2 + (y_island)^2
// we start by placing radar anywhere between x - r and x + r for first island (we always place it at x + r)
// if placing at x + r does not cover next island, add new radar
// else see if placing at x_i + r_i covers both or placing at x_{i+1} + r_{i+1} covers both (the min)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, caseNo = 1;
    nextCase:
    while (cin >> n >> d) {
        if (n == 0 && d == 0) break;
        cout << "Case " << caseNo++ << ": ";
        vector<pair<int, int>> islands(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            islands[i] = {x, y};
        }
        // can never reach
        for (auto island: islands) {
            if (island.second > d) {
                cout << -1 << endl;
                goto nextCase;
            }
        }
        vector<pair<double, double>> ranges(n);
        for (int i = 0; i < n; i++) {
            double x = islands[i].first;
            double y = islands[i].second;
            double range = sqrt(d * d - y * y);
            ranges[i] = {x - range, x + range};
        }
        sort(ranges.begin(), ranges.end());
        int radarCount = 1;
        double right = ranges[0].second; // furthest u can put current radar
        for (int i = 1; i < n; i++) {
            if (ranges[i].first > right) {
                radarCount++;
                right = ranges[i].second;
            } else {
                right = min(right, ranges[i].second);
            }
        }
        cout << radarCount << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
