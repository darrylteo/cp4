#include <bits/stdc++.h>

using namespace std;

// we have seen this trick before in kattis - ones

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s, s != "0"){
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = (ans * 10 + (s[i] - '0')) % 11;
        }
        cout << s << " is";
        if (ans) {
            cout << " not";
        }
        cout << " a multiple of 11.\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


