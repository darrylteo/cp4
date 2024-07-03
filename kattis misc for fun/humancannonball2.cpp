#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        double v, theta, x, h1, h2;
        cin >> v >> theta >> x >> h1 >> h2;
        double t = x / (v * cos(theta * M_PI / 180));
        double y = v * t * sin(theta * M_PI / 180) - 0.5 * 9.81 * t * t;
        if (y > h1 + 1 && y < h2 - 1) cout << "Safe\n";
        else cout << "Not Safe\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}