#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[19][10][2][2];
string s;

// if is_rising == true, select num >= prev to maintain is_rising == true. select num < prev to set is_rising == false
// if is_rising == false, select num <= prev

// if is_lower == true, select all numbers subject to is_rising condition
// if is_lower == false, select all numbers subject to is_rising condition and num <= s[pos]

ll dp(int pos, int prev, bool is_rising, bool is_lower) {
    if (pos == s.size()) return 1;
    ll &ans = memo[pos][prev][is_rising][is_lower];
    if (ans != -1) return ans;
    ans = 0; // clear and start finding values
    if (is_rising && is_lower) {
        for (int i = 0; i <= 9; i++) {
            ans += dp(pos + 1, i, i >= prev, true);
        }
    } else if (is_rising && !is_lower) {
        for (int i = 0; i <= 9; i++) {
            if (i <= s[pos] - '0') { // only can place if smaller than actual digit. when i == s[pos] - '0', we set is_lower to false
                ans += dp(pos + 1, i, i >= prev, i < s[pos] - '0');
            }
        }
    } else if (!is_rising && is_lower) {
        for (int i = 0; i <= prev; i++) {
            ans += dp(pos + 1, i, false, true);
        }
    } else if (!is_rising && !is_lower) {
        for (int i = 0; i <= prev; i++) {
            if (i <= s[pos] - '0') {
                ans += dp(pos + 1, i, false, i < s[pos] - '0');
            }
        }
    }
    return ans;
}

bool isHillNum(string num) {
    bool is_rising = true;
    for (int i = 1; i < num.size(); i++) {
        if (num[i - 1] > num[i]) {
            is_rising = false;
        }
        if (!is_rising) {
            if (num[i - 1] < num[i]) {
                return false;
            }
        }
    }
    return true;
}

// the is_lower in book notes say next_digit is lower than actual means we can select all the numbers since a larger number to the left was used
// e.g. 334455, and we are at 334. the next number can be from 0 to 4 since is_lower all prev numbers are same as original.
// if we are at 333, the next number can be from 0 to 9 since at least 1 prev number is lower than original.
// if is_lower == true, it will remain true since there was at least 1 bigger digit in front no matter what

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> s;
    if (!isHillNum(s)) {
        cout << -1 << '\n';
        return 0;
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, true, false) - 1 << '\n'; // -1 to exclude 0

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}