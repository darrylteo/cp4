#include <bits/stdc++.h>

using namespace std;

// Rabin-Karp's algorithm specific code
typedef long long ll;

const int MAX_N = 300010;

char T[MAX_N];
ll n;

const ll p = 131, p1 = 313;                      // p and p1 are primes
const ll M = 1e9 + 7, M1 = 1e9 + 9;                  // M and M1 are primes

ll Pow[MAX_N], Pow1[MAX_N];                      // to store p^i % M
ll h[MAX_N], h1[MAX_N];                          // rolling hashes

void computeRollingHash() {                      // Overall: O(n)
    Pow[0] = 1;                                    // compute p^i % M
    for (int i = 1; i < n; ++i)                    // O(n)
        Pow[i] = (Pow[i - 1] * p) % M;
    h[0] = 0;
    for (int i = 0; i < n; ++i) {                  // O(n)
        if (i != 0) h[i] = h[i - 1];                   // rolling hash
        h[i] = (h[i] + (T[i] * Pow[i]) % M) % M;
    }
    Pow1[0] = 1;                                    // compute p1^i % M1
    for (int i = 1; i < n; ++i)                    // O(n)
        Pow1[i] = ((ll) Pow1[i - 1] * p1) % M1;
    h1[0] = 0;
    for (int i = 0; i < n; ++i) {                  // O(n)
        if (i != 0) h1[i] = h1[i - 1];                 // rolling hash
        h1[i] = (h1[i] + (T[i] * Pow1[i]) % M1) % M1;
    }
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {    // pass x and y by ref
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {                                    // repeats until b == 0
        ll q = a / b;
        tie(a, b) = make_tuple(b, a % b);
        tie(x, xx) = make_tuple(xx, x - q * xx);
        tie(y, yy) = make_tuple(yy, y - q * yy);
    }
    return a;                                      // returns gcd(a, b)
}

ll modInverse(ll b, ll mm) {                   // returns b^(-1) (mod mm)
    ll x, y;
    ll d = extEuclid(b, mm, x, y);                 // to get b*x + mm*y == d
    if (d != 1) return -1;                         // to indicate failure
    // b*x + mm*y == 1, now apply (mod mm) to get b*x == 1 (mod mm)
    return (x + mm) % mm;                                // this is the answer
}

pair<int, int> hash_fast(int L, int R) {
    if (L == 0) return {h[R], h1[R]};                       // h is the prefix hashes
    ll ans = 0, ans1 = 0;
    ans = ((h[R] - h[L - 1]) % M + M) % M;           // compute differences
    ans = ((ll) ans * modInverse(Pow[L], M)) % M;   // remove P[L]^-1 (mod M)
    ans1 = ((h1[R] - h1[L - 1]) % M1 + M1) % M1;           // compute differences
    ans1 = ((ll) ans1 * modInverse(Pow1[L], M1)) % M1;   // remove P[L]^-1 (mod M)
    return {ans, ans1};
}

// mostly template code from book

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> T;
    n = (ll) strlen(T);
    computeRollingHash();
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        auto ans = hash_fast(L, R - 1);
        string str1 = to_string(ans.first);
        string str2 = to_string(ans.second);
        cout << str1 + str2 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
