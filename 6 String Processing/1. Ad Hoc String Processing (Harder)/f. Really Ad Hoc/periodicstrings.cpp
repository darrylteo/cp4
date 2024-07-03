#include <bits/stdc++.h>

using namespace std;

void rotate(string &s) {
    s = s.back() + s.substr(0, s.size() - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    for (int i = 1; i <= s.size(); ++i) {
        if (s.size() % i) continue; // can't find period

        string t = s.substr(0, i);
        string cmp = t;
        while (cmp.size() < s.size()) {
            rotate(t);
            cmp += t;
        }
        if (cmp == s) {
            cout << i << '\n';
            break;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

