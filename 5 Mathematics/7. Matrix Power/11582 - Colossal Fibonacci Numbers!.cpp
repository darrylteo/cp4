#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull modPow(ull a, ull b, ull n) {
    ull res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % n;
        }
        a = (a * a) % n;
        b >>= 1;
    }
    return res;
}

// need new formula else can't do
// ref: https://www.geeksforgeeks.org/fibonacci-number-modulo-m-and-pisano-period/
// we find the pisano period ourselves. google seach say no closed form
// largest pisano period from wiki (up to 144) seems to suggest it is grows in n^2 (look at pisano(50) = 300)
// either way, we need to find it so just do while(true) loop
// note no pisano for n = 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ull a, b, n;
        cin >> a >> b >> n;
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        vector<ull> fib;
        fib.push_back(0);
        fib.push_back(1);
        int period = 0;
        while (true) {
            fib.push_back((fib[fib.size() - 1] + fib[fib.size() - 2]) % n);
            period++;
            if (fib[fib.size() - 1] == 1 && fib[fib.size() - 2] == 0) {
                break;
            }
        }
        cout << fib[(modPow(a % period, b, period) % period)] << '\n';
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

