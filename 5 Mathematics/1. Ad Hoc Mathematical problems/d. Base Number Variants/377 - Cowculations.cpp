#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

inline string base10ToN(ll n, int base) {
    string digits = "VUCD";
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
    string digits = "VUCD";
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

    int T;
    cin >> T;
    cout << "COWCULATIONS OUTPUT\n";
    while (T--) {
        string a, b;
        cin >> a >> b;
        int aa = baseNTo10(a, 4), bb = baseNTo10(b, 4);
        for (int i = 0; i < 3; i++) {
            char c;
            cin >> c;
            if (c == 'A') {
                bb += aa;
            } else if (c == 'R') {
                bb /= 4;
            } else if (c == 'L') {
                bb *= 4;
            }
        }
        string c;
        cin >> c;
        int cc = baseNTo10(c, 4);
        if (cc == bb) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    cout << "END OF OUTPUT\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
