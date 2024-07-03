#include <bits/stdc++.h>

using namespace std;

#define MAXN 2000000

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;

bitset<MAXN> primes;
vi primesVec;

// sieve of eratosthenes. primes[i] = false if i is prime so i don't need to memset
inline void sieve() {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i < MAXN; i++) {
        if (!primes[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                primes[j] = true;
            }
        }
    }
}

inline bool isPrime(ull n) {
    if (n < MAXN) return !primes[n];
    for (ull i: primesVec) {
        if (i * i > n) break;
        if (n % i == 0) return false;
    }
    return true;
}

inline ull baseNTo10(const string &n, int base) {
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ull result = 0;
    for (char i: n) {
        if (digits.find(i) >= base) return -1; // invalid digit for base
        result = result * base + digits.find(i);
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    for (int i = 2; i < MAXN; i++) {
        if (!primes[i]) primesVec.push_back(i);
    }
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int baseCnt = 0, primeCnt = 0;
        ull n = baseNTo10(s, 2);
        if (n != -1) {
            baseCnt++;
            if (isPrime(n)) primeCnt++;
        }
        n = baseNTo10(s, 8);
        if (n != -1) {
            baseCnt++;
            if (isPrime(n)) primeCnt++;
        }
        n = baseNTo10(s, 10);
        if (n != -1) {
            baseCnt++;
            if (isPrime(n)) primeCnt++;
        }
        n = baseNTo10(s, 16);
        if (n != -1) {
            baseCnt++;
            if (isPrime(n)) primeCnt++;
        }
        int gcd = __gcd(baseCnt, primeCnt);
        cout << primeCnt / gcd << "/" << baseCnt / gcd << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}