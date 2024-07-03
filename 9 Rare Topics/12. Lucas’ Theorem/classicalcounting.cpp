#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll mod(ll a, ll m) {                           // returns a (mod m)
    return ((a % m) + m) % m;                        // ensure positive answer
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {    // pass x and y by ref
    int xx = y = 0;
    int yy = x = 1;
    while (b) {                                    // repeats until b == 0
        int q = a / b;
        tie(a, b) = tuple(b, a % b);
        tie(x, xx) = tuple(xx, x - q * xx);
        tie(y, yy) = tuple(yy, y - q * yy);
    }
    return a;                                      // returns gcd(a, b)
}

ll modInverse(ll b, ll m) {                   // returns b^(-1) (mod m)
    ll x, y;
    ll d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
    if (d != 1) return -1;                         // to indicate failure
    // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
    return mod(x, m);
}

vll MODS = {29, 34483}; // 29*34483 = 1000007
vector<vll> facts;

// code from book but need modify a little since we have more than 1 MOD
// this returns nCk % MOD
ll C(ll n, ll k, ll idx) {
    ll MOD = MODS[idx];
//    vll fact = facts[idx]; // don't make copy... it's slow esp in recursion
    if (n < k) return 0;
    if (n >= MOD) return (C(n % MOD, k % MOD, idx) * C(n / MOD, k / MOD, idx)) % MOD;
    return (((facts[idx][n] * modInverse(facts[idx][k], MOD)) % MOD) * modInverse(facts[idx][n - k], MOD)) % MOD;
}

ll crt(vll r, vll m) {
    // m_t = m_0*m_1*...*m_{n-1}
    ll mt = accumulate(m.begin(), m.end(), 1LL, multiplies<>());
    ll x = 0;
    for (int i = 0; i < (int) m.size(); ++i) {
        ll a = mod((ll) r[i] * modInverse(mt / m[i], m[i]), m[i]);
        x = mod(x + (ll) a * (mt / m[i]), mt);
    }
    return x;
}

// code from book website
// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_9_Rare_Topics/9.14_Lucas_Theorem/kattis_classicalcounting.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // book: If we first precompute all the factorial terms from 0
    // to p−1, then ni C ki mod p can be found in O(log p) with an O(p) preprocessing
    facts.assign(MODS.size(), vll());
    for (int i = 0; i < (int) MODS.size(); ++i) {
        facts[i].assign(MODS[i], 1);
        for (int j = 1; j < MODS[i]; ++j) {
            facts[i][j] = (facts[i][j - 1] * j) % MODS[i];
        }
    }

    ll n, m, k;
    cin >> n >> m >> k;

    // the plus and minus is from: https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle
    vll r;
    for (int j = 0; j < (int) MODS.size(); j++) {
        ll ans = 0;
        for (ll i = 0; (i <= n) && (k >= i * (m + 1)); i++) {
            ans += (i % 2 ? -1 : 1) * C(n, i, j) * C(n - 1 + k - i * (m + 1), n - 1, j);
            ans %= MODS[j];
        }
        r.emplace_back(ans);
    }
    cout << crt(r, MODS) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
