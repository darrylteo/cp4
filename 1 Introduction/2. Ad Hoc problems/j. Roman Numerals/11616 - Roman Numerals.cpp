#include <bits/stdc++.h>

using namespace std;

const vector<pair<string, int>> roman = {
        {"M",  1000},
        {"CM", 900},
        {"D",  500},
        {"CD", 400},
        {"C",  100},
        {"XC", 90},
        {"L",  50},
        {"XL", 40},
        {"X",  10},
        {"IX", 9},
        {"V",  5},
        {"IV", 4},
        {"I",  1}
};

//https://www.geeksforgeeks.org/validating-roman-numerals-using-regular-expression/
const regex pattern("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");

int romanToDecimal(string &s) {
    if (!regex_match(s, pattern)) return -1;
    int ans = 0;
    for (int i = 0; i < roman.size(); ++i) {
        while (s.substr(0, roman[i].first.size()) == roman[i].first) { // while since III or XXX
            ans += roman[i].second;
            s = s.substr(roman[i].first.size());
        }
    }
    return ans;
}

string decimalToRoman(int n) {
    string ans;
    for (int i = 0; i < roman.size(); ++i) {
        while (n >= roman[i].second) {
            ans += roman[i].first;
            n -= roman[i].second;
        }
    }
    return ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    while (cin >> s){
        if (isdigit(s[0])) cout << decimalToRoman(stoi(s)) << endl;
        else cout << romanToDecimal(s) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


