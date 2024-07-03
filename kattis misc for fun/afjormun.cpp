#include <bits/stdc++.h>

using namespace std;

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
        s[0] = (char) toupper(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (isalpha(s[i])) {
                s[i] = (char) tolower(s[i]);
            }
        }
        cout << s << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

