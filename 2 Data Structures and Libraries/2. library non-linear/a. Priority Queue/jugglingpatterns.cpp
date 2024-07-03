#include <bits/stdc++.h>

using namespace std;

// weird qn idk what is it, had to read and understand the concept behind the qn
// https://cp-wiki.vercel.app/en/ad-hoc/#kattis-juggling-patterns
// another reference on section 4: https://www.qedcat.com/articles/juggling_survey.pdf
// main result: length of string = period. if the balls all land on different beats in period, it is jugglable

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    while (cin >> s) {
        cout << s << ": ";
        vector<int> v(s.length());
        for (int i = 0; i < s.length(); i++) {
            v[i] = s[i] - '0';
        }
        if (accumulate(v.begin(), v.end(), 0) % v.size() != 0) {
            cout << "invalid # of balls" << endl;
            continue;
        }
        int noBalls = accumulate(v.begin(), v.end(), 0) / v.size();

        set<int> times;
        for (int i = 0; i < v.size(); i++) {
            times.insert((i + v[i]) % v.size());
        }
        if (times.size() != v.size()) {
            cout << "invalid pattern" << endl;
            continue;
        } else {
            cout << "valid with " << noBalls << " balls" << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
