#include <bits/stdc++.h>

using namespace std;

inline bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (getline(cin, s)) {
        if (s == "e/o/i") {
            break;
        }
        vector<int> cnt(3, 0);
        int lineNo = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') {
                lineNo++;
            } else if (isVowel(s[i])) {
                if (i == 0 || !isVowel(s[i - 1])) {
                    cnt[lineNo]++;
                }
            }
        }
        if (cnt[0] != 5) {
            cout << "1\n";
        } else if (cnt[1] != 7) {
            cout << "2\n";
        } else if (cnt[2] != 5) {
            cout << "3\n";
        } else {
            cout << "Y\n";
        }
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

