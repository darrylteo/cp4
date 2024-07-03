#include <bits/stdc++.h>

using namespace std;

string removeSpaces(const string &s) {
    string result;
    for (char c: s) {
        if (c != ' ') {
            c = (char) toupper(c);
            result += c;
        }
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n >> ws, n) {
        string s;
        getline(cin, s);
        s = removeSpaces(s);
        string ans(s.size(), ' ');
        int idx = 0;
        for (int i = 0; i < n; ++i) { // number of loops
            for (int j = i; j < s.size(); j += n) {
                ans[j] = s[idx++];
            }
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

