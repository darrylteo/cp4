#include <bits/stdc++.h>

using namespace std;

// duno how it applies to steiner tree...
// just scuttle around and find best point

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double x1, y1, x2, y2, x3, y3, x4 = 0, y4 = 0; // start anywhere is fine
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double best = hypot(x4 - x1, y4 - y1) + hypot(x4 - x2, y4 - y2) + hypot(x4 - x3, y4 - y3), sz = 100;
    while (sz > 1e-6) {
        for (int i = 0; i < 10; i++) {
            double x = x4 + (rand() % 100 - 50) * sz; // -50 to get negative vals from -50 to 50
            double y = y4 + (rand() % 100 - 50) * sz;
            double d = hypot(x - x1, y - y1) + hypot(x - x2, y - y2) + hypot(x - x3, y - y3);
            if (d < best) {
                best = d;
                x4 = x;
                y4 = y;
            }
        }
        sz *= 0.99;
    }
    cout << fixed << setprecision(9) << x4 << " " << y4 << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
