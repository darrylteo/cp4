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
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

    string s1, s2;
    while (cin >> s1 >> s2) {
        int found = 0;
        for (int i = 2; i <= 36; i++) {
            for (int j = 2; j <= 36; j++) {
                if (baseNTo10(s1, i) == baseNTo10(s2, j) && baseNTo10(s1, i) != -1) {
                    found = 1;
                    cout << s1 << " (base " << i << ") = " << s2 << " (base " << j << ")\n";
                    break;
                }
            }
            if (found) break;
        }
        if (!found) cout << s1 << " is not equal to " << s2 << " in any base 2..36\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
