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

    string s;
    cin >> s;
    while (s.size() % 4) s = "0" + s;
    string ans;
    for (int i = 0; i < s.size(); i += 4) {
        string tmp = base10ToN(baseNTo10(s.substr(i, 4), 8), 16);
        while (tmp.size() != 3) tmp = "0" + tmp;
        ans += tmp;
    }
    while (ans.size() > 1 && ans[0] == '0') ans = ans.substr(1);
    cout << ans << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
