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


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    while (s.size() % 3 != 0) s = "0" + s;
    string result;
    for (int i = 0; i < s.size(); i += 3) {
        string temp = s.substr(i, 3);
        if (temp == "000") result += "0";
        else if (temp == "001") result += "1";
        else if (temp == "010") result += "2";
        else if (temp == "011") result += "3";
        else if (temp == "100") result += "4";
        else if (temp == "101") result += "5";
        else if (temp == "110") result += "6";
        else if (temp == "111") result += "7";
    }
    cout << result;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
