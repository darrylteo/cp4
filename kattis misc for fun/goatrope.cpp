#include <bits/stdc++.h>

using namespace std;

// if not up down left right of house, check distance from each corner

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    double ans;
    if (x > x2 && y >= y1 && y <= y2) ans = x - x2;
    else if (x < x1 && y >= y1 && y <= y2) ans = x1 - x;
    else if (y > y2 && x >= x1 && x <= x2) ans = y - y2;
    else if (y < y1 && x >= x1 && x <= x2) ans = y1 - y;
    else {
        double a = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        double b = sqrt((x - x2) * (x - x2) + (y - y1) * (y - y1));
        double c = sqrt((x - x1) * (x - x1) + (y - y2) * (y - y2));
        double d = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        ans = min(a, min(b, min(c, d)));
    }
    cout << fixed << setprecision(5) << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}