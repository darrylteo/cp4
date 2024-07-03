#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 int128;

ll p, n, m;
ll MOD = 1e9 + 7;
unordered_map<ll, ll> pi;  // pi[prime] = exp, ie prime^exp is part of the prime factorisation

ll mod(ll a, ll b) { return (a % b + b) % b; }
ll power(int128 x, int128 y, int128 p) {
    int128 res = 1;  // Initialize result
    x = x % p;       // Update x if it is more than or
    // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res * x) % p;

        // y must be even now
        y = y >> 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}
bool millerTest(ll d, ll n) {
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    ll a = 2 + rand() % (n - 4);

    // Compute a^d % n
    int128 x = power(a, d, n);

    if (x == 1 || x == n - 1) return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    // Return composite
    return false;
}
bool isPrime(ll n, int k = 4) {
    // Corner cases
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;

    // Iterate given number of 'k' times
    for (int i = 0; i < k; i++)
        if (!millerTest(d, n)) return false;

    return true;
}
ll Rho(ll n) {
    if (n % 2 == 0) return 2;
    ll x = (rand() % (n - 2)) + 2;
    ll y = x;
    ll c = (rand() % (n - 1)) + 1;

    ll d = 1;
    while (d == 1) {
        /* Tortoise Move: x(i+1) = f(x(i)) */
        x = (power(x, 2, n) + c + n) % n;

        /* Hare Move: y(i+1) = f(f(y(i))) */
        y = (power(y, 2, n) + c + n) % n;
        y = (power(y, 2, n) + c + n) % n;

        /* check gcd of |x-y| and n */
        d = __gcd(abs(x - y), n);
        if (d == n) return Rho(n);
    }

    return d;
}
ll brent(ll n) {
    if (n % 2 == 0) return 2;
    ll y = rand() % (n - 1) + 1;
    ll c = rand() % (n - 1) + 1;
    ll m = rand() % (n - 1) + 1;
    ll g = 1, r = 1, q = 1;
    ll ys, x;
    while (g == 1) {
        x = y;
        for (int i = 0; i < r; i++) {
            y = (power(y, 2, n) + c + n) % n;
        }
        ll k = 0;
        while (k < r && g == 1) {
            ys = y;
            for (ll i = 0; i < min(m, r - k); i++) {
                y = (power(y, 2, n) + c + n) % n;
                q = ((int128)q * (int128)(abs((x - y)))) % n;
            }
            g = gcd(q, n);
            k = k + m;
        }
        r = r * 2;
    }
    if (g == n) {
        while (1) {
            ys = (power(ys, 2, n) + c + n) % n;
            g = gcd(abs((x - ys)), n);
            if (g > 1) break;
        }
    }

    return g;
}
void PollardRho(ll n, ll adding) {
    if (n == 1) return;  // # no prime divisor for 1
    if (isPrime(n)) {
        if (pi.find(n) == pi.end()) {
            pi[n] = 0;
        }
        pi[n] += adding;
        return;
    }

    ll d = brent(n);  // try changing to rho (brent is the upgraded version)

    PollardRho(d, adding);
    PollardRho(n / d, adding);
}

// since book say details not important, for now, we just copy "template" code above from:
// https://rextester.com/discussion/TIJY97700/Pollard-Rho-Brent-Integer-Factorization-11476-Factorizing-Larget-Integers
// code from above website worked for the previous uva question but TLE here sadly.
// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_9_Rare_Topics/9.12_Pollard_Rho/kattis_atrivialpursuit.cpp
// of which he referenced:
// https://xn--2-umb.com/09/12/brent-pollard-rho-factorisation/
// https://www.geeksforgeeks.org/pollards-rho-algorithm-prime-factorization/
// https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/
// after getting the powers of each prime factor in LCM and GCD,
// thinking in terms of prime factors, each of the x terms must contain between minPow and maxPow for each prime factor
// W(.) := num ways for each prime factor (later just multiply across all prime factors), tMin and tMax is number of terms with minPow and maxPow in x
// W(tMin>=1 & tMax>=1) = W(all) - W(tMin == 0 | tMax == 0)
//                      = W(all) - (W(tMin==0) + W(tMax==0) - W(tMin==0 & tMax==0))
//                      = (maxPow - minPow + 1) ^ P - 2 * (maxPow - minPow) ^ P + (maxPow - minPow - 1) ^ P
// we collate the prime factors in MAP by adding primes when considering LCM, and subtracting primes when considering GCD
// else hard to match terms between two maps,
// for e.g. checking if GCD has a term that LCM does not (to output 0) would be hard if not merged. see sample 2, 2^3 in GCD but not LCM and output 0

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll P, N, M;
    cin >> P >> N >> M;
    while (N--) {
        ll g;
        cin >> g;
        PollardRho(g, -1); // subtract for GCD
    }
    while (M--) {
        ll l;
        cin >> l;
        PollardRho(l, 1); // add for LCM
    }
    ll ans = 1;
    int ok = 1;
    for (auto [pr, diff]: pi) { // prime, maxPow - minPow
        if (diff < 0) {
            ok = 0;
            break;
        }
        if (diff == 0) continue; // this prime, in all terms, remains at minPow == maxPow
        ll W = power(diff + 1, P, MOD) % MOD;
        W -= 2 * power(diff, P, MOD);
        W = mod(W, MOD);
        W += power(diff - 1, P, MOD) % MOD;
        W = mod(W, MOD);
        ans *= W;
        ans %= MOD;
    }
    if (!ok) cout << 0 << endl;
    else cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
