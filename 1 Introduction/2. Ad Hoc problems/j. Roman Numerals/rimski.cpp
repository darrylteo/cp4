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

int romanToDecimal(string s) {
    if (!regex_match(s, pattern)) return 10000;
    int ans = 0;
    for (int i = 0; i < roman.size(); ++i) {
        while (s.substr(0, roman[i].first.size()) == roman[i].first) { // while since III or XXX
            ans += roman[i].second;
            s = s.substr(roman[i].first.size());
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s, minRoman;
    int min = 10000;
    cin >> s;
    sort(s.begin(), s.end());
    do {
        if (romanToDecimal(s) < min) {
            min = romanToDecimal(s);
            minRoman = s;
        }
    }
    while (next_permutation(s.begin(), s.end()));
    cout << minRoman << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}