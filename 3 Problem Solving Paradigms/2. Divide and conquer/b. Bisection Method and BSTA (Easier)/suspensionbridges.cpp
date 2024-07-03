#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, s;
    cin >> d >> s;
    double l = 0, r = 1e9;
    // kinda weird. 1e-9 doesn't work nor does 1e-11
    // my guess is sinh function is very sensitive to small changes
    while (r - l > 1e-10) {
        double a = (l + r) / 2;
        if (a + s >= a * cosh(d / (2 * a))) {
            r = a;
        } else {
            l = a;
        }
    }
    cout << fixed << setprecision(10) << 2 * l * sinh(d / (2 * l)) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
