#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// just gotta trust the qn that any permutation is divisible by 9?

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s) {
        sort(s.begin(), s.end(), greater<char>());
        ull a = stoull(s);
        sort(s.begin(), s.end());
        int idx = 0;
        while (s[0] == '0') {
            swap(s[0], s[++idx]);
        }
        ull b = stoull(s);
        cout << a << " - " << b << " = " << a - b << " = 9 * " << (a - b) / 9 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


