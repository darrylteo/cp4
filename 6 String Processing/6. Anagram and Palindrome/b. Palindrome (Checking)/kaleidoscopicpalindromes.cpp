#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

string decToBaseN(int n, int base) {
    string s;
    while (n) {
        s += to_string(n % base);
        n /= base;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = a; i <= b; ++i) {
        int allOk = 1;
        for (int base = 2; base <= c; ++base) {
            string s = decToBaseN(i, base);
            if (!isPalindrome(s)) {
                allOk = 0;
                break;
            }
        }
        ans += allOk;
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
