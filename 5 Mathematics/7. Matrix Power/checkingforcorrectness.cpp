#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull MOD = 1000000000;

inline ull modPow(ull a, ull b) {
    ull res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull a, b;
    char op;
    while (cin >> a >> op >> b) {
        if (op == '+') {
            cout << (a + b) % 10000 << '\n';
        } else if (op == '*') {
            cout << (a * b) % 10000 << '\n';
        } else {
            cout << modPow(a, b) % 10000 << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

