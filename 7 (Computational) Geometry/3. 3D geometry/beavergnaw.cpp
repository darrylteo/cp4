#include <bits/stdc++.h>

using namespace std;

// remaining = pi * (D/2)^2 * D - V = pi * (D^3 / 4) - V
// remaining = 2 * 1/3 * pi * ((D/2)^3 - (d/2)^3) + pi * d^3 / 4 (2 frustums and a cylinder)
//           = 1/3 * pi * (D^3 / 4 + d^3 / 2)
// 3 * D^3 / 4 - 3 * V / pi = D^3 / 4 + d^3 / 2
// d^3 = D^3 - 6 * V / pi


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double D, V;
    while (cin >> D >> V, D) {
        double d = pow(D * D * D - 6 * V / M_PI, 1.0 / 3.0);
        cout << fixed << setprecision(10) << d << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}