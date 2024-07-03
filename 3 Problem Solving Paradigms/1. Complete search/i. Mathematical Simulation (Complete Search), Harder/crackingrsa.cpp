#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

// quite a long reading ... a lot of redundant info particularly about the M
// we have de-1=k*phi
// d = (k*phi+1)/e IFF d and k are ints i.e., check for each int d, whether (de-1)%phi==0

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1000);
    int T;
    cin >> T;
    next:
    while (T--) {
        long long n, e;
        cin >> n >> e;
        for (int prime : primes) {
            if (prime >= n) {
                break;
            }
            // other factor must be prime too
            if (n % prime == 0 && find(primes.begin(), primes.end(), n / prime) != primes.end()) {
                long long p = prime, q = n / prime;
                long long phi = (p - 1) * (q - 1);
                for (long long d = 2; d < phi; ++d) {
                    if ((d * e - 1) % phi == 0) {
                        cout << d << '\n';
                        goto next;
                    }
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}