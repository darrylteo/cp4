#include <bits/stdc++.h>

using namespace std;

// ref: https://theinnerframe.org/2021/01/03/euclids-game/

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    while (cin >> x >> y, x) {
        if (x > y) swap(x, y);
        if (y % x == 0 || (double) y / x > 1.618) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}