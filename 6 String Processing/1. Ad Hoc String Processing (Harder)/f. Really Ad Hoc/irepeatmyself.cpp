#include <bits/stdc++.h>

using namespace std;

bool prefixMatches(string pref, string word) {
    int ok = 1;
    for (int i = 0; i < pref.size(); ++i) {
        if (pref[i] != word[i]) {
            ok = 0;
            break;
        }
    }
    if (ok) return true;
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T >> ws;
    while (T--) {
        string s;
        getline(cin, s);
        for (int i = 1; i <= s.size(); ++i) {
            string tmp = s.substr(0, i);
            string longWord = tmp;
            for (int j = 0; j < s.size() / i; ++j) {
                longWord += tmp;
            }
            if (prefixMatches(s, longWord)) {
                cout << i << '\n';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

