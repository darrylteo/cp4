#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// each foot count individually

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull a, b, c, d, e;
    while (cin >> a >> b >> c >> d >> e, a) {
        cout << a * b * c * d * d * e * e << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


