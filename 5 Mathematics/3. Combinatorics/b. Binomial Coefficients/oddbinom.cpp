#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// ref: https://oeis.org/A006046

inline ull A006046(ull n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2 == 0) return 3 * A006046(n / 2);
    return 2 * A006046((n - 1) / 2) + A006046((n + 1) / 2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    cin >> n;
    cout << A006046(n) << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


