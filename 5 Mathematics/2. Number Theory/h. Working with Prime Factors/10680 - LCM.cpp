#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000010

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;

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

ull modPow(ull a, ull b, ull mod) {
    ull res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// highest possible power is when the prime fac is by itself.. e.g. for 25, highest is 2^4, 3^2, 5^2, 7^1, 11^1, 13^1, 17^1, 19^1, 23^1.
// get the highest possible power for all prime factors up to n, remove pairs of 2s and 5s to avoid trailing zeroes. we remove 2 pairs for above example
// multiply all the remaining mod 10 i.e. get last digit
// special note: the fact of 2s and 5s for trailing zeroes is super common in this chapter
// my method is probably wrong... very slow. just passed

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
        map<int, int> maxPower;
        for (int prime: primesVec) {
            if (prime > n) break;
            maxPower[prime%10] += (int) (log(n) / log(prime)); // round down. get last digit only.
        }
        maxPower[2] -= maxPower[5];
        maxPower.erase(5);
        ull lastDigit = 1;
        for (auto &p: maxPower) {
            lastDigit = (lastDigit * modPow(p.first, p.second, 10)) % 10; // good thing we used this trick b4
        }
        cout << lastDigit << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}