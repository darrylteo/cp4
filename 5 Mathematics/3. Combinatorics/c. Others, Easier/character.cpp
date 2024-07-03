#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull fastPow(ull a, ull b) {
    ull res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}

// https://oeis.org/A000295

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    cin >> n;
    cout << fastPow(2, n) - n - 1 << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


