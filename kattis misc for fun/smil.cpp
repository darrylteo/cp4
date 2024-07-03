#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] == ':' && s[i + 1] == ')') || (s[i] == ';' && s[i + 1] == ')') ||
            (s[i] == ':' && s[i + 1] == '-' && s[i + 2] == ')') || (s[i] == ';' && s[i + 1] == '-' && s[i + 2] == ')')) {
            cout << i << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


