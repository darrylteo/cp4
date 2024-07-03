#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// cnt good string with 0 at end = a, cnt good string with 1 at end = b
// a(2) = 2, b(2) = 1, cnt = 3
// a(3) = a(2) + b(2) since can always add 0 behind, b(3) = a(2) since can only add when 0 last time, cnt = 2*a(2) + b(2) = f(2) = 5
// a(4) = a(3) + b(3), b(4) = a(3), cnt = 2*a(3) + b(3) = f(3) = 8
// can take function f() as a fib.

// 0 1
// 00 01 10
// 000 001 010 100 101
// 0000 0001 0010 0100 1000 0101 1001 1010
// 00000 00001 00010 00100 01000 10000 00101 01001 10001 01010 10010 10100 10101

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> fibs(10000 + 10);
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i <= 10004; i++) {
        fibs[i] = (fibs[i - 1] + fibs[i - 2])%1000000007;
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << fibs[n + 2] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


