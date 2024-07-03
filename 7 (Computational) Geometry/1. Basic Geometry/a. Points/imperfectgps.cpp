#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<point> a(n);
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> times[i];
    }
    double actualDist = 0;
    for (int i = 1; i < n; i++) {
        actualDist += sqrt((a[i].x - a[i - 1].x) * (a[i].x - a[i - 1].x) + (a[i].y - a[i - 1].y) * (a[i].y - a[i - 1].y));
    }
    vector<point> gps;
    int time = 0;
    for (; time <= times.back(); time += t) {
        int pos = lower_bound(times.begin(), times.end(), time) - times.begin(); // gives which times is greater or equal to time
        if (pos == 0) {
            gps.emplace_back(point{a[0].x, a[0].y});
        } else {
            double x = a[pos - 1].x + (a[pos].x - a[pos - 1].x) * (time - times[pos - 1]) / (times[pos] - times[pos - 1]);
            double y = a[pos - 1].y + (a[pos].y - a[pos - 1].y) * (time - times[pos - 1]) / (times[pos] - times[pos - 1]);
            gps.emplace_back(point{x, y});
        }
    }
    if (time != times.back()) {
        gps.emplace_back(point{a.back().x, a.back().y});
    }
    double gpsDist = 0;
    for (int i = 1; i < gps.size(); i++) {
        gpsDist += sqrt((gps[i].x - gps[i - 1].x) * (gps[i].x - gps[i - 1].x) + (gps[i].y - gps[i - 1].y) * (gps[i].y - gps[i - 1].y));
    }
    cout << fixed << setprecision(10) << (actualDist - gpsDist) / actualDist * 100 << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}