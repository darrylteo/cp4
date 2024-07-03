#include <bits/stdc++.h>

using namespace std;

#define MAXN 320

typedef vector<int> vi;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

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

ll sumDiv(ll N) {
    ll ans = 1; // start from ans = 1
    for (int i = 0; (i < (int)primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i) {
        ll multiplier = primesVec[i], total = 1;
        while (N % primesVec[i] == 0) {
            N /= primesVec[i];
            total += multiplier;
            multiplier *= primesVec[i];
        } // total for
        ans *= total; // this prime factor
    }
    if (N != 1) ans *= (N+1); // N^2-1/N-1 = N+1
    return ans;
}

int numDiv(ll N) {
    int ans = 1; // start from ans = 1
    for (int i = 0; (i < (int)primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i) {
        int power = 0; // count the power
        while (N % primesVec[i] == 0) { N /= primesVec[i]; ++power; }
        ans *= power+1; // follow the formula
    }
    return (N != 1) ? 2*ans : ans; // last factor = N^1
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    for (int i = 2; i < MAXN; ++i) {
        if (!primes[i]) { // if is prime
            primesVec.push_back(i);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int a, b, k;
        cin >> a >> b >> k;
        ll ansG = 0, ansH = 0;
        for (int i = a; i <= b; ++i) {
            if (i % k == 0) {
                ansG += numDiv(i);
                ansH += sumDiv(i);
            }
        }
        cout << ansG << " " << ansH << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}