#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010 // exceed 10000 so we don't double count for 9973 (so that we add a number and check, not check itself twice)

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
        int cnt = 0, curr;

        for (int i = 0; i < primesVec.size(); ++i) {
            curr = primesVec[i];
            if (curr == n) ++cnt;
            for (int j = i + 1; j < primesVec.size(); ++j) {
                curr += primesVec[j];
                if (curr >= n) break;
            }
            if (curr == n) ++cnt;
        }
        cout << cnt << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}