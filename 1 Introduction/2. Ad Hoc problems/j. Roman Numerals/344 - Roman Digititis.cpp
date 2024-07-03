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

string decimalToRoman(int n) {
    string ans;
    for (int i = 0; i < roman.size(); ++i) {
        while (n >= roman[i].second) { // while since can have up to 3 of the same roman numeral e.g. III or XXX
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

    vector<string> v;
    for (int i = 1; i <= 100; ++i) {
        v.push_back(decimalToRoman(i));
    }

    int n, iCnt, vCnt, xCnt, lCnt, cCnt;
    while(cin >> n) {
        if (n == 0) break;
        iCnt = vCnt = xCnt = lCnt = cCnt = 0;
        for (int i = 0; i < n; ++i) {
            for (char c : v[i]) {
                if (c == 'I') iCnt++;
                else if (c == 'V') vCnt++;
                else if (c == 'X') xCnt++;
                else if (c == 'L') lCnt++;
                else if (c == 'C') cCnt++;
            }
        }
        cout << n << ": " << iCnt << " i, " << vCnt << " v, " << xCnt << " x, " << lCnt << " l, " << cCnt << " c" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


