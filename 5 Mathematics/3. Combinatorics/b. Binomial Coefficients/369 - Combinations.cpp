#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull nCk(ull n, ull k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    ull result = n;
    for (ull i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n, k;
    while (cin >> n >> k, n) {
        cout << n << " things taken " << k << " at a time is " << nCk(n, k) << " exactly." << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


