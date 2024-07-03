#include <bits/stdc++.h>

using namespace std;

#define MAXN 47000

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

    int N;
    while (cin >> N) {
        if (N < 0) {
            cout << "-1 ";
            N = -N;
        }

        vll factors = primeFactors(N);
        factors.push_back(-1); // sentinel value to avoid out of bounds (i + 1)
        int cnt = 0;
        for (int i = 0; i < (int) factors.size() - 1; ++i) {
            if (factors[i] == factors[i + 1]) {
                cnt++;
            } else {
                cout << factors[i];
                if (cnt > 0) {
                    cout << "^" << cnt + 1 << " ";
                } else {
                    cout << " ";
                }
                cnt = 0;
            }
        }
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}