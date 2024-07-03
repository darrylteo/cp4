#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        for (int i = 1; i <= s.size(); ++i) {
            if (s.size() % i == 0) {
                string temp = s.substr(0, i);
                string ans;
                for (int j = 0; j < s.size() / i; ++j) {
                    ans += temp;
                }
                if (ans == s) {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

