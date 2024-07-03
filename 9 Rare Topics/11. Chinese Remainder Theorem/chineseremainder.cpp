#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

//const int MAXN = 1000005; // has the largest prime at MAXN-1
//bitset<MAXN> prime;
//vll p;
//
//void sieve() {
//    prime.set();
//    prime[0] = prime[1] = false;
//    for (ll i = 2; i < MAXN; i++) {
//        if (prime[i]) {
//            for (ll j = i * i; j < MAXN; j += i) {
//                prime[j] = false;
//            }
//        }
//    }
//    for (ll i = 2; i < MAXN; i++) {
//        if (prime[i]) p.push_back(i);
//    }
//}
//
//vector<ll> primeFactors(ll n) {
//    vector<ll> factors;
//    ll x = n, idx = 0;
//    while (!prime[x]) {
//        if (x % p[idx] == 0) {
//            factors.push_back(p[idx]);
//            x /= p[idx];
//        } else idx++;
//    }
//    factors.push_back(x);
//    return factors;
//}

ll mod(ll a, ll m) {                           // returns a (mod m)
    return ((a % m) + m) % m;                        // ensure positive answer
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {    // pass x and y by ref
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {                                    // repeats until b == 0
        ll q = a / b;
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

//ll fastPow(ll b, ll e) {
//    ll r = 1;
//    while (e > 0) {
//        if (e & 1) r = (r * b);
//        b = b * b;
//        e >>= 1;
//    }
//    return r;
//}

ll crt(vll r, vll m) {
    // check if all pairs are pairwise coprime
//    ll g = m[0];
//    for (int i = 1; i < (int) m.size(); ++i) {
//        g = __gcd(g, m[i]);
//    }
//    if (g != 1) { // need to redo vectors r and m
//        map<ll, pair<ll, ll>> mp; // base -> (pow, remainder)
//        // factor each m[i] into base^pow, and store it IF base is new or pow is higher
//        // this forms the new set of m and r. test on book
//        // x ⌘ 400 (mod 600)
//        // x ⌘ 190 (mod 270)
//        // x ⌘ 40  (mod 240)
//        // ans should be 1000
//        for (int j = 0; j < (int) m.size(); ++j) {
//            ll mm = m[j];
//            vector<ll> factors = primeFactors(mm);
//            ll base = -1, pows = -1;
//            for (int i = 0; i < (int) factors.size(); ++i) {
//                if (i == 0 || factors[i] != factors[i - 1]) {
//                    if ((mp.find(base) == mp.end() || mp[base].first < pows) && base != -1) {
//                        mp[base] = {pows, r[j]}; // we get the updated remainder later
//                    }
//                    base = factors[i];
//                    pows = 1;
//                } else {
//                    pows++;
//                }
//            }
//            if ((mp.find(base) == mp.end() || mp[base].first < pows) && base != -1) { // last one
//                mp[base] = {pows, r[j]}; // we get the updated remainder later
//            }
//        }
//        r.clear();
//        m.clear();
//        for (auto &it: mp) {
//            ll newBase = fastPow(it.first, it.second.first);
//            ll newRemainder = mod(it.second.second, newBase);
//            r.push_back(newRemainder);
//            m.push_back(newBase);
//        }
//    }
    // m_t = m_0*m_1*...*m_{n-1}
    ll mt = 1;
    for (long long i : m) mt *= i;
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

    // test book - need uncomment everything above
//    sieve();
//    vll r = {400, 190, 40};
//    vll m = {600, 270, 240};
//    cout << crt(r, m) << endl; // 1000

    int T;
    cin >> T;
    while (T--) {
        ll a, n, b, m;
        cin >> a >> n >> b >> m;
        vll r = {a, b};
        vll mm = {n, m};
        cout << crt(r, mm) << " " << n * m << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
