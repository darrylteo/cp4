#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;

bitset<MAXN> primes;
vull primesVec;

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

inline vull primeFactors(ull N) { // pre-condition, N >= 1
    vull factors;
    for (int i = 0; (i < (int)primesVec.size()) && (primesVec[i]*primesVec[i] <= N); ++i)
        while (N%primesVec[i] == 0) { // found a prime for N
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
        if (!primes[i]) primesVec.push_back(i);
    }
    int n;
    while (cin >> n, n) {
        if (n < 0) {
            cout << n << " = -1 x ";
            n = -n;
        } else {
            cout << n << " = ";
        }
        vull factors = primeFactors(n);
        for (int i = 0; i < (int)factors.size(); ++i) {
            cout << factors[i];
            if (i < (int)factors.size() - 1) cout << " x ";
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}