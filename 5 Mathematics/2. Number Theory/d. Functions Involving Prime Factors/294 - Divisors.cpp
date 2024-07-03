#include <bits/stdc++.h>

using namespace std;

#define MAXN 432

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

int numDiv(ull N) {
    int ans = 1; // start from ans = 1
    for (int i = 0; (i < (int) primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i) {
        int power = 0; // count the power
        while (N % primesVec[i] == 0) {
            N /= primesVec[i];
            ++power;
        }
        ans *= power + 1; // follow the formula
    }
    return (N != 1) ? 2 * ans : ans; // last factor = N^1
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
    for (int t = 1; t <= T; ++t) {
        ull L, U;
        cin >> L >> U;
        ull maxDiv = 0, maxNum = 0;
        for (ull i = L; i <= U; ++i) {
            int div = numDiv(i);
            if (div > maxDiv) {
                maxDiv = div;
                maxNum = i;
            }
        }
        cout << "Between " << L << " and " << U << ", " << maxNum << " has a maximum of " << maxDiv << " divisors." << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}