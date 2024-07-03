#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;

bitset<MAXN> primes; // if int array, MLE
vi primesVec;

// sieve of eratosthenes. primes[i] = false if i is prime so i don't need to memset
void sieve() {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i < MAXN; i++) {
        if (!primes[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                primes[j] = true;
            }
        }
    }
}

bool isPrime(int n) {
    if (n < MAXN) return !primes[n];
    for (int i : primesVec) {
        if (i * i > n) break;
        if (n % i == 0) return false;
    }
    return true;
}

// prime testing by checking if any primes up to sqrt(n) divides n

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    int n;
    for (int i = 2; i < MAXN; i++) {
        if (!primes[i]) {
            primesVec.push_back(i);
        }
    }
    while (cin >> n, n) {
        int n2 = 2 * n;
        while (!isPrime(n2)) {
            n2++;
        }
        cout << n2;
        if (!isPrime(n)) {
            cout << " (" << n << " is not prime)";
        }
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}