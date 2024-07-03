#include <bits/stdc++.h>

using namespace std;

// a + b + c + d = a * b * c * d
// d = (a + b + c) / (a * b * c - 1)
// a little tricky comparing doubles to ints

#define eps 1e-6

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // gives ans
    for (int i1 = 1; i1 < 2000; ++i1) {
        for (int i2 = i1; i1 + i2 < 2000; ++i2) {
            for (int i3 = i2; i1 + i2 + i3 < 2000; ++i3) {
                double i1d = i1 / 100.0;
                double i2d = i2 / 100.0;
                double i3d = i3 / 100.0;
                double d = (i1d + i2d + i3d) / (i1d * i2d * i3d - 1);
                if (d > 0 && i1d + i2d + i3d + d <= 20 + eps && abs(d * 100 - (int) (d * 100 + eps)) < 1e-7 &&
                    d + eps >= i3d) {
                    cout << fixed << setprecision(2) << i1d << " " << i2d << " " << i3d << " " << d << '\n';
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
