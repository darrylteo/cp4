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
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Case " << cases << ": ";
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        if (s1 == s2) {
            cout << "Yes\n";
        } else {
            s1.erase(remove_if(s1.begin(), s1.end(), [](char c) { return c == ' '; }), s1.end());
            s2.erase(remove_if(s2.begin(), s2.end(), [](char c) { return c == ' '; }), s2.end());
            if (s1 == s2) {
                cout << "Output Format Error\n";
            } else {
                cout << "Wrong Answer\n";
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




