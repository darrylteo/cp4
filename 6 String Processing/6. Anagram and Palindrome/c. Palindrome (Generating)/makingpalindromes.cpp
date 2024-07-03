#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

// standard function
ll modPow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

string s;
ll memo[205][205][205];

// k is a ticking time bomb that goes to 0,
// and is also the pos i and 2n - i - 1 where we decide to put a char s[i], s[2n - i - 1], or other alphabet
// if l and r go to 0 first, means we finished using s, good, can permute the remaining chars,
// else if k go to 0 first, we didn't finish using s, so is invalid
inline ll dp(int l, int r, int k) {
    if (l > r) return modPow(26, k);
    if (!k) return 0;
    if (r - l + 1 > k * 2) return 0;
    ll &ret = memo[l][r][k];
    if (ret != -1) return ret;
    if (s[l] == s[r]) {
        ret = dp(l + 1, r - 1, k - 1) + (dp(l, r, k - 1) * 25) % MOD;
    } else {
        ret = (dp(l + 1, r, k - 1) + dp(l, r - 1, k - 1)) + (dp(l, r, k - 1) * 24) % MOD;
    }
    ret %= MOD;
    return ret;
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_6_String_Processing/Anagram_and_Palindrome/kattis_makingpalindromes.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n >> s;
    if (!n) {
        cout << 1 << endl;
        return 0;
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, n - 1, n) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}