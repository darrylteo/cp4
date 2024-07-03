#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double r, h, s;
    while (cin >> r >> h >> s, r) {
        double ans = sqrt(h * h - r * r) * 2; // straight parts
        ans += (2 * M_PI - 2 * acos(r / h)) * r; // circular parts
        ans *= 1 + s / 100; // tie knot
        cout << fixed << setprecision(2) << round(ans * 100) / 100 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}