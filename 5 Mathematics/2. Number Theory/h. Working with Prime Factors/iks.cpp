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

// sample input 2:
// 3
// 8 24 9
// 2^3, 2^3*3, 3^2
// total is 2^6*3^3. each power divide nums.size=3 so best gcd is 2^2*3^1 = 12
// num shifts = count powers smaller than gcd so we donate to them = 3


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
    cin >> n;
    vector<map<ull, int>> freq;
    map<ull, int> freqTotal;
    while (n--) {
        ull num;
        cin >> num;
        vull factors = primeFactors(num);
        map<ull, int> f;
        for (auto &factor : factors) {
            f[factor]++;
            freqTotal[factor]++;
        }
        freq.push_back(f);
    }

    int GCD = 1;
    for (auto &f : freqTotal) {
        GCD *= pow(f.first, f.second / (int)freq.size());
    }

    int shifts = 0;
    for (auto &f : freqTotal) {
        ull base = f.first;
        int power = f.second / (int)freq.size();
        for (auto &f2 : freq) {
            if (f2[base] < power) {
                shifts += power - f2[base];
            }
        }
    }

    cout << GCD << " " << shifts << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}