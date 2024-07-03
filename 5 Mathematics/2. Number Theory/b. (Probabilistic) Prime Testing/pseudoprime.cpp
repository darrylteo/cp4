#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;

bitset<MAXN> primes;
vi primesVec;

// sieve of eratosthenes. primes[i] = false if i is prime so i don't need to memset
inline void sieve() {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i < MAXN; i++) {
        if (!primes[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                primes[j] = true;
            }
        }
    }
}

inline bool isPrime(int n) {
    if (n < MAXN) return !primes[n];
    for (int i : primesVec) {
        if (i * i > n) break;
        if (n % i == 0) return false;
    }
    return true;
}

inline ull modpow(ull base, ull exp, ull modulus) {
    base %= modulus;
    ull result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    for (int i = 2; i < MAXN; i++) {
        if (!primes[i]) primesVec.push_back(i);
    }
    ull p, a;
    while (cin >> p >> a, p) {
        if (isPrime((int)p)) {
            cout << "no\n";
        } else {
            if (modpow(a, p, p) == a) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}