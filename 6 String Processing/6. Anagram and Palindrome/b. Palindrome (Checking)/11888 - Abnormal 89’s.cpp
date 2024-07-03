#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string ss = s;
        ss += s;
        reverse(s.begin(), s.end());
        int alin = 0;
        for (int i = 1; i < s.size(); ++i) {
            int j;
            for (j = 0; j < s.size(); ++j) {
                if (s[j] != ss[i + j]) {
                    break;
                }
            }
            if (j == s.size()) {
                alin = 1;
                break;
            }
        }
        if (alin) {
            cout << "alindrome\n";
        } else if (isPalindrome(s)) {
            cout << "palindrome\n";
        } else {
            cout << "simple\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
