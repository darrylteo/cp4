#include <bits/stdc++.h>

using namespace std;

// https://en.wikipedia.org/wiki/Brahmagupta%27s_formula
// -_-

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double s = (a + b + c + d) / 2;
    cout << setprecision(8) << sqrt((s - a) * (s - b) * (s - c) * (s - d)) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}