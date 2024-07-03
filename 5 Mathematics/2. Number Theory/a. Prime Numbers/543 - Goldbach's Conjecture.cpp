#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int primes[MAXN];

// sieve of eratosthenes. primes[i] = 0 if i is prime so i don't need to memset
void sieve() {
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
    int n;
    while (cin >> n, n) {
        for (int i = 2; i <= n / 2; i++) {
            if (primes[i] == 0 && primes[n - i] == 0) {
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}