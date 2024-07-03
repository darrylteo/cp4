#include <bits/stdc++.h>

using namespace std;

// at most 1 letter is allowed to be odd. let this be the largest letter

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s, s != "#") {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
            }
        }

        if (odd == 0 || odd == 1) {
            cout << '\n';
            continue;
        }

        for (int i = 0; i < 26; i++) {
            if (odd == 1) break;
            if (cnt[i] % 2) {
                cout << (char) (i + 'a');
                odd--;
            }
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
