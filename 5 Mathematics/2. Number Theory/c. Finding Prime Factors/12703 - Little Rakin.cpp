#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005

typedef vector<int> vi;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bitset<MAXN> primes;
vi primesVec;

// sieve of eratosthenes. primes[i] = false if i is prime so i don't need to memset
inline void sieve() {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i < MAXN; ++i) {
        if (!primes[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                primes[j] = true;
            }
        }
    }
}

vll primeFactors(ll N) { // pre-condition, N >= 1
    vll factors;
    for (int i = 0; (i < (int)primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i)
        while (N % primesVec[i] == 0) { // found a prime for N
            N /= primesVec[i]; // remove it from N
            factors.push_back(primesVec[i]);
        }
    if (N != 1) factors.push_back(N); // remaining N is a prime
    return factors;
}

vll fib(ll n) {
    vll v;
    v.push_back(1);
    v.push_back(1);
    for (int i = 2; i < n; ++i) {
        v.push_back(v[i - 1] + v[i - 2]);
    }
    return v;
}

// F_0 = a
// F_1 = b
// F_2 = a * b
// F_3 = a * b^2
// F_4 = a^2 * b^3
// F_5 = a^3 * b^5
// F_6 = a^5 * b^8
// powers are fibonacci numbers

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    for (int i = 2; i < MAXN; ++i) {
        if (!primes[i]) primesVec.push_back(i);
    }
    vll fibs = fib(45);

    int T;
    cin >> T;
    while (T--) {
        ll n, a, b;
        cin >> n >> a >> b;
        vll aFactors = primeFactors(a);
        vll bFactors = primeFactors(b);
        vi aCount(MAXN, 0), bCount(MAXN, 0);
        for (auto &factor : aFactors) {
            aCount[factor]++;
        }
        for (auto &factor : bFactors) {
            bCount[factor]++;
        }
        int aPow = fibs[n - 2], bPow = fibs[n - 1];
        vi ans(MAXN, 0);
        for (int i = 0; i < MAXN; ++i) {
            aCount[i] *= aPow;
            bCount[i] *= bPow;
            ans[i] = aCount[i] + bCount[i];
        }
        for (int i = 0; i < MAXN; ++i) {
            if (ans[i] > 0) {
                cout << i << " " << ans[i] << endl;
            }
        }

        cout << endl;
    }
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}