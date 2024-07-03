#include <bits/stdc++.h>

using namespace std;

// number of bounces is the number of table lengths it moves

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, s, m, n;
    while (cin >> a >> b >> s >> m >> n, a) {
        int x = m * a, y = n * b;
        cout << fixed << setprecision(2) << atan2(y, x) * 180 / M_PI << " " << hypot(x, y) / s << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}