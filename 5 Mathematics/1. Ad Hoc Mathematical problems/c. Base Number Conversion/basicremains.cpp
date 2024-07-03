#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// works for base 2 to 16
string base10ToN(ll n, int base) {
    string digits = "0123456789ABCDEF";
    string result;
    while (n > 0) {
        result += digits[n % base];
        n /= base;
    }
    reverse(result.begin(), result.end());
    if (result.empty()) result = "0";
    return result;
}

ll baseNTo10(const string &n, int base) {
    string digits = "0123456789ABCDEF";
    ll result = 0;
    for (char i: n) {
        result = result * base + digits.find(i);
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int base;
    while (cin >> base, base) {
        string p, m;
        cin >> p >> m;
        if (m == "0") {
            cout << p << '\n';
            continue;
        }
        // same method as baseNTo10 just with mod m
        ll mod = 0;
        for (char i: m) {
            mod = mod * base + (i - '0');
        }
        ll res = 0;
        for (char i: p) {
            res = (res * base + (i - '0')) % mod;
        }
        cout << base10ToN(res, base) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
