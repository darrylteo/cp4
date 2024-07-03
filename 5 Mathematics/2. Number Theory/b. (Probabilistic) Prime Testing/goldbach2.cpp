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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> goldbach;
        for (int i = 2; i <= n / 2; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                goldbach.emplace_back(i, n - i);
            }
        }
        cout << n << " has " << goldbach.size() << " representation(s)\n";
        for (auto &i : goldbach) {
            cout << i.first << "+" << i.second << '\n';
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}