#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

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
    string digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    ll result = 0;
    for (char i: n) {
        if (digits.find(i) >= base) return -1; // invalid digit for base
        result = result * base + digits.find(i);
    }
    return result;
}

bool checkBaseOne(const string &n) {
    for (char i: n) {
        if (i != '1') return false;
    }
    return true;
}

// see 7th example for base 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string gene = "-123456789abcdefghijklmnopqrstuvwxyz0";
    string a, b, c, op;
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> op >> b >> c >> c;
        string ans;
        for (int base = 1; base <= 36; base++) {
            ll a10 = baseNTo10(a, base);
            ll b10 = baseNTo10(b, base);
            ll c10 = baseNTo10(c, base);
            if (base == 1 && checkBaseOne(a) && checkBaseOne(b) && checkBaseOne(c)) {
                a10 = a.size();
                b10 = b.size();
                c10 = c.size();
            }
            if (base == 1 && a10 == 0 && b10 == 0 && c10 == 0) continue; // 0 is not valid in base 1
            if (a10 == -1 || b10 == -1 || c10 == -1) continue;
            if (op == "+") {
                if (a10 + b10 == c10) {
                    ans += gene[base];
                }
            } else if (op == "-") {
                if (a10 - b10 == c10) {
                    ans += gene[base];
                }
            } else if (op == "*") {
                if (a10 * b10 == c10) {
                    ans += gene[base];
                }
            } else if (op == "/") {
                if (b10 != 0 && a10 / b10 == c10 && a10 % b10 == 0) {
                    ans += gene[base];
                }
            }
        }
        if (ans.empty()) cout << "invalid" << '\n';
        else cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
