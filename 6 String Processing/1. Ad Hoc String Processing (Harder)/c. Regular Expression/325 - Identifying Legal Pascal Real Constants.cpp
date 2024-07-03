#include <bits/stdc++.h>

using namespace std;

// square brackets to match either + or -. then ? to match 0 or 1 time. then \\d+ to match 1 or more digits.
// second part means if have decimal, the exponent part is optional. otherwise must have exponent part.
bool legalPascal(const string& s) {
    if (regex_match(s, regex("[+-]?\\d+((\\.\\d+([eE][+-]?\\d+)?)|([eE][+-]?\\d+))"))) {
        return true;
    }
    return false;
}

void clearWhitespace(string& s) {
    while (s.back() == ' ' || s.back() == '\t') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    while (s.back() == ' ' || s.back() == '\t') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (getline(cin, s)) {
        clearWhitespace(s);
        if (s == "*") break;
        if (legalPascal(s)) cout << s << " is legal.\n";
        else cout << s << " is illegal.\n";
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

