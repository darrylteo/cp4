#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000000

typedef vector<int> vi;
typedef unsigned long long ull;
typedef long long ll;
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

ll biggestPF(ll N) {
    ll ans;
    int types = 0;
    for (int i = 0; (i < (int) primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i) {
        int flag = 0; // if the prime is a factor
        while (N % primesVec[i] == 0) {
            N /= primesVec[i];
            ans = primesVec[i];
            flag = 1;
        }
        if (flag) types++;
    }
    if (N > 1) {
        ans = N;
        types++;
    }
    if (types < 2) {
        return -1;
    } else {
        return ans;
    }
}

// -_- there can be negative numbers!!

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

    ll N;
    while (cin >> N, N) {
        cout << biggestPF(abs(N)) << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}