#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MAXN = 1000005; // has the largest prime at (MAXN-1)^2
bitset<MAXN> prime;
vll p;

void sieve() {
    prime.set();
    prime[0] = prime[1] = false;
    for (ll i = 2; i < MAXN; i++) {
        if (prime[i]) {
            for (ll j = i * i; j < MAXN; j += i) {
                prime[j] = false;
            }
        }
    }
    for (ll i = 2; i < MAXN; i++) {
        if (prime[i]) p.push_back(i);
    }
}

bool isPrime(ll n) {
    if (n < MAXN) return prime[n];
    for (ll i: p) {
        if (n % i == 0) return false;
    }
    return true;
}

vll primeFactors(ll n) {
    vll factors;
    ll x = n, idx = 0;
    while (!isPrime(x)) {
        if (x % p[idx] == 0) {
            factors.push_back(p[idx]);
            x /= p[idx];
        } else idx++;
    }
    factors.push_back(x);
    return factors;
}

ll mod(ll a, ll n) { return (a % n + n) % n; }

ll extEuclid(ll a, ll b, ll &x, ll &y) {  // pass x and y by ref
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {  // repeats until b == 0
        ll q = a / b;
        tie(a, b) = tuple(b, a % b);
        tie(x, xx) = tuple(xx, x - q * xx);
        tie(y, yy) = tuple(yy, y - q * yy);
    }
    return a;  // returns gcd(a, b)
}

ll modInverse(ll a, ll n) {  // returns modular inverse of a mod n
    ll x, y;
    extEuclid(a, n, x, y);
    return mod(x, n);
}

ll fastPow(ll b, ll e) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = (r * b);
        b = b * b;
        e >>= 1;
    }
    return r;
}

bool okcrt(vll r, vll m) {
    for (int i = 0; i < (int) m.size(); ++i) {
        for (int j = i + 1; j < (int) m.size(); ++j) {
            if (mod(r[i], __gcd(m[i], m[j])) != mod(r[j], __gcd(m[i], m[j]))) {
                return false;
            }
        }
    }
    return true;
}

ll mt = 1;

ll crt(vll r, vll m) {
    if (!okcrt(r, m)) return -1; // no solution
    map<ll, pair<ll, ll>> mp; // base -> (pow, remainder)
    // factor each m[i] into base^pow, and store it IF base is new or pow is higher
    // this forms the new set of m and r. test on book
    // x ⌘ 400 (mod 600)
    // x ⌘ 190 (mod 270)
    // x ⌘ 40  (mod 240)
    // ans should be 1000
    for (int j = 0; j < (int) m.size(); ++j) {
        ll mm = m[j];
        vll factors = primeFactors(mm);
        ll base = -1, pows = -1;
        for (int i = 0; i < (int) factors.size(); ++i) {
            if (i == 0 || factors[i] != factors[i - 1]) {
                if ((mp.find(base) == mp.end() || mp[base].first < pows) && base != -1) {
                    mp[base] = {pows, r[j]}; // we get the updated remainder later
                }
                base = factors[i];
                pows = 1;
            } else {
                pows++;
            }
        }
        if ((mp.find(base) == mp.end() || mp[base].first < pows) && base != -1) { // last one
            mp[base] = {pows, r[j]}; // we get the updated remainder later
        }
    }
    r.clear();
    m.clear();
    for (auto &it: mp) {
        ll newBase = fastPow(it.first, it.second.first);
        ll newRemainder = mod(it.second.second, newBase);
        r.push_back(newRemainder);
        m.push_back(newBase);
    }
    // m_t = m_0*m_1*...*m_{n-1}

    for (ll i: m) mt *= i;
    ll x = 0;
    for (int i = 0; i < (int) m.size(); ++i) {
        ll a = mod(r[i] * modInverse(mt / m[i], m[i]), m[i]);
        x = mod(x + a * (mt / m[i]), mt);
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    vector<int> v;
    for (int i = 1; i * 2 < a; ++i) { // size of square cut out (also the height of the box formed)
        int base = (a - 2 * i) * (b - 2 * i); // base area of the box
        v.push_back(base * i); // volume of the box
    }
    sort(v.begin(), v.end());
    int n = v.size();
    vll r = {c, d, e};
    vll m = {v[n - 1], v[n - 2], v[n - 3]};
    ll ans = crt(r, m);
    // bring ans up to >= f
    while (ans < f) ans += mt;
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
