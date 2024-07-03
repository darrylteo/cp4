#include <bits/stdc++.h>

using namespace std;

#define MAXN 505

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

inline vll primeFactors(ll N) { // pre-condition, N >= 1
    vll factors;
    for (int i = 0; (i < (int) primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i)
        while (N % primesVec[i] == 0) { // found a prime for N
            N /= primesVec[i]; // remove it from N
            factors.push_back(primesVec[i]);
        }
    if (N != 1) factors.push_back(N); // remaining N is a prime
    return factors;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    for (int i = 2; i < MAXN; ++i) {
        if (!primes[i]) { // if is prime
            primesVec.push_back(i);
        }
    }
    
    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        vll factors = primeFactors(N);
        int sign = 1;
        for (ll factor : factors) {
            if (factor % 4 == 1) {
                sign *= -1;
            }
        }
        if (sign == 1) {
            cout << "+\n";
        } else {
            cout << "-\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}