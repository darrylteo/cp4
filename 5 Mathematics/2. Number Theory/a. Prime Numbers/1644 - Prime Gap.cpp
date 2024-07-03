#include <bits/stdc++.h>
using namespace std;

#define MAXN 1300005

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
        if (primes[n] == 0) {
            cout << 0 << '\n';
        } else {
            int i = n;
            while (primes[i] == 1) {
                i--;
            }
            int j = n;
            while (primes[j] == 1) {
                j++;
            }
            cout << j - i << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}