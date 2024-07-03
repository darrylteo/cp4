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

ull EulerPhi(ull N) {
    ull ans = N; // start from ans = N
    for (int i = 0; (i < (int)primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i) {
        if (N % primesVec[i] == 0) ans -= ans / primesVec[i]; // count unique
        while (N % primesVec[i] == 0) N /= primesVec[i]; // prime factor
    }
    if (N != 1) ans -= ans/N; // last factor
    return ans;
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
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        cout << EulerPhi(n) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}