#include <bits/stdc++.h>

using namespace std;

#define MAXN 50005

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

ll EulerPhi(ll N) {
    ll ans = N; // start from ans = N
    for (int i = 0; (i < (int) primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i) {
        if (N % primesVec[i] == 0) ans -= ans / primesVec[i]; // count unique
        while (N % primesVec[i] == 0) N /= primesVec[i]; // prime factor
    }
    if (N != 1) ans -= ans / N; // last factor
    return ans;
}

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// not obvious at all to use Modular Multiplicative Inverse ....

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

    int T;
    cin >> T;
    while (T--) {
        ll m, b;
        cin >> m >> b;
        if (__gcd(m, b) != 1) {
            cout << "IMPOSSIBLE\n";
        } else if (b == 1) { // catch this else b^pow will return 1 wrongly
            cout << m + 1 << '\n';
        } else {
            ll pow = EulerPhi(m) - 1;
            cout << modpow(b, pow, m) << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


