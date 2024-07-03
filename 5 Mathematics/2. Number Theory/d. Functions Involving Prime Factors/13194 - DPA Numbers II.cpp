#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

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

ull sumDiv(ull N) {
    ull ans = 1; // start from ans = 1
    for (int i = 0; (i < (int) primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i) {
        ull multiplier = primesVec[i], total = 1;
        while (N % primesVec[i] == 0) {
            N /= primesVec[i];
            total += multiplier;
            multiplier *= primesVec[i];
        } // total for
        ans *= total; // this prime factor
    }
    if (N != 1) ans *= (N + 1); // N^2-1/N-1 = N+1
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

    int T;
    cin >> T;
    while (T--) {
        ull N;
        cin >> N;
        ull ans = sumDiv(N) - N;
        if (ans == N) cout << "perfect\n";
        else if (ans < N) cout << "deficient\n";
        else cout << "abundant\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}