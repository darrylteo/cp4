#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// ref: https://oeis.org/A173196

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    while (cin >> n, n > 2) {
        cout << (2 * n * n * n - 9 * n * n + 10 * n) / 24 << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


