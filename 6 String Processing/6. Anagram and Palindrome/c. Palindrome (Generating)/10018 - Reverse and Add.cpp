#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long cnt = 0, num;
        cin >> num;
        // 0 iterations not allowed
        string s = to_string(num);
        reverse(s.begin(), s.end());
        num += stoll(s);
        cnt++;
        // search for palindrome
        while (true) {
            s = to_string(num);
            if (isPalindrome(s)) {
                cout << cnt << ' ' << num << '\n';
                break;
            }
            reverse(s.begin(), s.end());
            num += stoll(s);
            cnt++;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}