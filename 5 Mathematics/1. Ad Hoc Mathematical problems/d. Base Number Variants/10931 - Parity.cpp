#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

inline string base10ToN(ll n, int base) {
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

inline ll baseNTo10(const string &n, int base) {
    string digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    ll result = 0;
    for (char i: n) {
        if (digits.find(i) >= base) return -1; // invalid digit for base
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

    int n;
    while (cin >> n, n) {
        cout << "The parity of " << base10ToN(n, 2) << " is " << __builtin_popcount(n) << " (mod 2).\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
