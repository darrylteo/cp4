#include <bits/stdc++.h>

using namespace std;

#define MAXN 2005
#define MAXNN 2000000

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

int numPF(ull N) {
    if (N == 1) return 1;
    int ans = 0;
    for (int i = 0; (i < (int)primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i)
        while (N % primesVec[i] == 0) { N /= primesVec[i]; ++ans; }

    return ans + (N != 1);
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
    vector<pair<int, int>> v; // (numPF, i)
    for (int i = 1; i <= MAXNN; ++i) {
        v.emplace_back(numPF(i), i);
    }
    sort(v.begin(), v.end());
    int n, cases = 1;
    while (cin >> n, n) {
        cout << "Case " << cases++ << ": " << v[n - 1].second << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}