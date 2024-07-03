#include <bits/stdc++.h>

using namespace std;

int degree(string s) {
    if (s == "9") {
        return 0;
    }
    int next = 0;
    for (char i : s) {
        next += (i - '0');
    }
    return degree(to_string(next)) + 1;
}

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
            ans = (ans * 10 + (s[i] - '0')) % 9;
        }
        if (ans == 0) {
            cout << s << " is a multiple of 9 and has 9-degree " << max(1, degree(s)) << ".\n";
        } else {
            cout << s << " is not a multiple of 9.\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


