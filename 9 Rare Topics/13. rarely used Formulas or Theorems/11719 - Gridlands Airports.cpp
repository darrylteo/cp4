#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD = 10000000000000007;

// prevent the usual b*b overflow
// https://www.geeksforgeeks.org/multiply-large-integers-under-large-modulo/
ll modMult(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modPow(ll b, ll e, ll mod) {
    ll res = 1;
    b %= mod;
    while (e > 0) {
        if (e & 1) res = modMult(res, b, mod);
        b = modMult(b, b, mod);
        e >>= 1;
    }
    return res;
}

// close to impossible to identify MST on complete bipartite graph ._.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        ll m = a * b / 2; // half squares on one side
        ll n = a * b - m; // remaining squares on the other
        // apply formula
        ll x = modPow(m, n - 1, MOD);
        ll y = modPow(n, m - 1, MOD);
        ll ans = modMult(x, y, MOD);
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

