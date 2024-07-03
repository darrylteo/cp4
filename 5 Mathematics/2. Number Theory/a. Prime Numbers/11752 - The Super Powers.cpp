#include <bits/stdc++.h>

using namespace std;

#define MAXN 70000

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;

int primes[MAXN];
const ull MAXULL = pow(2, 64) - 1;

// sieve of eratosthenes. primes[i] = 0 if i is prime so i don't need to memset
inline void sieve() {
    primes[0] = primes[1] = 1;
    for (int i = 2; i * i < MAXN; i++) {
        if (primes[i] == 0) {
            for (int j = i * i; j < MAXN; j += i) {
                primes[j] = 1;
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
    set<ull> ans;
    ans.insert(1);
    for (int base = 2; base <= pow(2, 16); ++base) {
        ull num = base;
        for (int exp = 2; exp <= 64; ++exp) {
            if (num > MAXULL / base) {
                break;
            }
            num *= base;
            if (primes[exp] == 1) { // is composite
                ans.insert(num);
            }
        }
    }
    for (auto &x : ans) {
        cout << x << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}