#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[15][85][85][2];
string s;
int k;

inline ll dp(int pos, int sum, int num, int is_lower) {
    if (pos == s.size()) return sum == 0 && num == 0;
    ll &ans = memo[pos][sum][num][is_lower];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 0; i <= 9; i++) {
        if (is_lower || i <= s[pos] - '0') {
            ans += dp(pos + 1, (sum + i) % k, (num * 10 + i) % k, is_lower || i < s[pos] - '0');
        }
    }
    return ans;
}

// we need to keep track of pos, sum, and the number itself, and is_lower. see kattis hillnumbers for explanation on is_lower. if is_lower == true. can test from 0 to 9. else up to s[pos] - '0'
// there are overlapping subproblems since the number can range from 1 to 2^31 - 1 but we only need to keep track mod k,
// where the largest value of k is 82. since 1999999999 sum of digits is 82.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b >> k;
        if (k > 82) {
            cout << 0 << '\n';
            continue;
        }
        s = to_string(b);
        memset(memo, -1, sizeof(memo));
        ll ans = dp(0, 0, 0, 0);
        s = to_string(a - 1);
        memset(memo, -1, sizeof(memo));
        ans -= dp(0, 0, 0, 0);
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}