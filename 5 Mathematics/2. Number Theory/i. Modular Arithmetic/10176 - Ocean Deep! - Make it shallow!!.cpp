#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 131071

inline ll modPow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s, curr;
    while (cin >> s) {
        while (s.back() != '#') {
            cin >> curr;
            s += curr;
        }
        s.pop_back();
        reverse(s.begin(), s.end());
        ll res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                res += modPow(2, i, MOD);
                res %= MOD;
            }
        }
        if (res == 0) cout << "YES\n";
        else cout << "NO\n";
        curr = "";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}