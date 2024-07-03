#include <bits/stdc++.h>

using namespace std;

// close call to TLE... took 2s with 3s limit
// we haven't learned backtracking but Halim recommends it here :(
// arabic check is about 10-20x slower than roman check.. partly cuz stoi() slow :P

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
        while (s.substr(0, roman[i].first.size()) == roman[i].first) {
            ans += roman[i].second;
            s = s.substr(roman[i].first.size());
        }
    }
    return ans;
}


bool checkRomanSum(const char a[], const char b[], const char c[]) {
    string a1 = a, b1 = b, c1 = c;
    int x = romanToDecimal(a1);
    int y = romanToDecimal(b1);
    int z = romanToDecimal(c1);
    if (x == -1 || y == -1 || z == -1 || x + y != z) return false;
    return true;
}

int charToArabic(const char a[], const int curr[]) {
    string s = a;
    for (char &i: s) {
        if (i == 'I') i = curr[0] + '0';
        else if (i == 'V') i = curr[1] + '0';
        else if (i == 'X') i = curr[2] + '0';
        else if (i == 'L') i = curr[3] + '0';
        else if (i == 'C') i = curr[4] + '0';
        else if (i == 'D') i = curr[5] + '0';
        else if (i == 'M') i = curr[6] + '0';
    }
    if (s[0] == '0') return 100000000;
    return stoi(s);
}

int checkArabicSum(char a[], char b[], char c[], vector<bool> exists) {
    string a1 = a, b1 = b, c1 = c;

    // i, v, x, l, c, d, m
    int curr[7] = {};
    int cnt = 0; // all 0s case is handled by if (s[0] == '0') return 100000;
    int i1c = exists[0] ? 10 : 1;
    int i2c = exists[1] ? 10 : 1;
    int i3c = exists[2] ? 10 : 1;
    int i4c = exists[3] ? 10 : 1;
    int i5c = exists[4] ? 10 : 1;
    int i6c = exists[5] ? 10 : 1;
    int i7c = exists[6] ? 10 : 1;

    for (int i1 = 0; i1 < i1c; i1++){
        for (int i2 = 0; i2 < i2c; i2++){
            for (int i3 = 0; i3 < i3c; i3++){
                for (int i4 = 0; i4 < i4c; i4++){
                    for (int i5 = 0; i5 < i5c; i5++){
                        for (int i6 = 0; i6 < i6c; i6++){
                            for (int i7 = 0; i7 < i7c; i7++){
                                curr[0] = i1;
                                curr[1] = i2;
                                curr[2] = i3;
                                curr[3] = i4;
                                curr[4] = i5;
                                curr[5] = i6;
                                curr[6] = i7;
                                if (charToArabic(a, curr) + charToArabic(b, curr) == charToArabic(c, curr)) cnt++;
                                if (cnt > 1) return cnt; // sure ambiguous
                            }
                        }
                    }
                }
            }
        }
    }

    return cnt;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    char a[10], b[10], c[10];
    while (cin >> s, s != "#") {
        vector<bool> exists = {false, false, false, false, false, false, false};
        for (char i: s) {
            if (i == 'I') exists[0] = true;
            else if (i == 'V') exists[1] = true;
            else if (i == 'X') exists[2] = true;
            else if (i == 'L') exists[3] = true;
            else if (i == 'C') exists[4] = true;
            else if (i == 'D') exists[5] = true;
            else if (i == 'M') exists[6] = true;
        }

        char *pch = strtok((char *) s.c_str(), "+=");
        strcpy(a, pch);
        pch = strtok(NULL, "+=");
        strcpy(b, pch);
        pch = strtok(NULL, "+=");
        strcpy(c, pch);

        if (checkRomanSum(a, b, c)) cout << "Correct ";
        else cout << "Incorrect ";

        int cnt = checkArabicSum(a, b, c, exists);
        if (cnt == 0) cout << "impossible" << endl;
        else if (cnt == 1) cout << "valid" << endl;
        else cout << "ambiguous" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


