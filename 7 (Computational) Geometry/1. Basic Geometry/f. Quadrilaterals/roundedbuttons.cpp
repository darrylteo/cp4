#include <bits/stdc++.h>

using namespace std;

// i drew a thick cross to mark the area in rect that is not curved

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        double x, y, w, h, r;
        cin >> x >> y >> w >> h >> r;
        // sure in rects
        double minx1 = x + r, miny1 = y, maxx1 = x + w - r, maxy1 = y + h;
        double minx2 = x, miny2 = y + r, maxx2 = x + w, maxy2 = y + h - r;
        // circles center
        double cx1 = x + r, cy1 = y + r;
        double cx2 = x + w - r, cy2 = y + r;
        double cx3 = x + w - r, cy3 = y + h - r;
        double cx4 = x + r, cy4 = y + h - r;
        // queries
        int m;
        cin >> m;
        while (m--) {
            double a, b;
            cin >> a >> b;
            if (a >= minx1 && a <= maxx1 && b >= miny1 && b <= maxy1) {
                cout << "inside\n";
            } else if (a >= minx2 && a <= maxx2 && b >= miny2 && b <= maxy2) {
                cout << "inside\n";
            } else if (sqrt((a - cx1) * (a - cx1) + (b - cy1) * (b - cy1)) <= r) {
                cout << "inside\n";
            } else if (sqrt((a - cx2) * (a - cx2) + (b - cy2) * (b - cy2)) <= r) {
                cout << "inside\n";
            } else if (sqrt((a - cx3) * (a - cx3) + (b - cy3) * (b - cy3)) <= r) {
                cout << "inside\n";
            } else if (sqrt((a - cx4) * (a - cx4) + (b - cy4) * (b - cy4)) <= r) {
                cout << "inside\n";
            } else {
                cout << "outside\n";
            }
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}