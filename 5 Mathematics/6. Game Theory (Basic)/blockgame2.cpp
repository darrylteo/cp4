#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// ref: https://theinnerframe.org/2021/01/03/euclids-game/

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    long double a = (long double) y / x;
    long double five = 5;
    if (y % x == 0 || a > (1 + sqrt(five)) / 2) cout << "win\n";
    else cout << "lose\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}