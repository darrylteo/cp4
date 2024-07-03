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

    int n;
    const vector<int> cnt = {1,2,2,2,2,3,4};
    const vector<char> romanChar = {'I','V','X','L','C','D','M'};
    vector<int> v;
    while (cin >> n){
        v = {0,0,0,0,0,0,0};
        string romanForm = decimalToRoman(n);
        for (int i = 0; i < romanForm.size(); ++i) {
            for (int j = 0; j < romanChar.size(); ++j) { // j matches the index of romanChar (and cnt)
                if (romanForm[i] == romanChar[j]){
                    v[j] += cnt[j];
                }
            }
        }
        cout << accumulate(v.begin(), v.end(), 0) << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


