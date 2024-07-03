#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// ref: https://www.cnblogs.com/shentr/p/5285134.html
// super shortcut :O
// summary of the solution:
// 1. sq numbers have odd sum of divisors since u need odd base and odd power to get even sum of divisors
// 2. sq numbers * 2 also have odd sum of divisors. book says 2^k but of course we could factorize k/2 into sq numbers and k%2 as the power so only 0 or 1.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    while (cin >> n, n) {
        ull a = sqrt(n);
        ull b = sqrt(n / 2.0);
        cout << n - a - b << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}