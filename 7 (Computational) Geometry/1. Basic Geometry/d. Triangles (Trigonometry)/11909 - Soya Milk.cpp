#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, w, h, theta;
    while (cin >> l >> w >> h >> theta) {
        double theta_rad = theta * M_PI / 180;
        if (tan(theta_rad) * l <= h) // the little triangle on top is inside the box
            cout << fixed << setprecision(3) << l * w * h - 0.5 * (tan(theta_rad) * l) * l * w << " mL\n";
        else // the little triangle is not a triangle. so we calculate the triangle at bottom of box
            cout << fixed << setprecision(3) << 0.5 * (tan(M_PI / 2 - theta_rad) * h) * h * w << " mL\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}