#include <bits/stdc++.h>

using namespace std;

// Rabin-Karp's algorithm specific code
typedef long long ll;

string T;
ll n;

const ll p = 131, p1 = 177;                      // p and p1 are primes
const ll M1 = 1e9 + 7, M2 = (1LL << 31) - 1;                  // M1 and M2 are primes

vector<ll> h1, h2, Pow1, Pow2;

// templatey stuff to use pair as key in unordered_map
struct pair_hash {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

inline void computeRollingHash() {                      // Overall: O(n)
    h1[0] = 0;
    for (int i = 0; i < n; ++i) {                  // O(n)
        if (i != 0) h1[i] = h1[i - 1];                   // rolling hash
        h1[i] = (h1[i] + (T[i] * Pow1[i]) % M1) % M1;
    }
    h2[0] = 0;
    for (int i = 0; i < n; ++i) {                  // O(n)
        if (i != 0) h2[i] = h2[i - 1];                 // rolling hash
        h2[i] = (h2[i] + (T[i] * Pow2[i]) % M2) % M2;
    }
}

inline ll extEuclid(ll a, ll b, ll &x, ll &y) {    // pass x and y by ref
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

inline ll modInverse(ll b, ll mm) {                   // returns b^(-1) (mod mm)
    ll x, y;
    ll d = extEuclid(b, mm, x, y);                 // to get b*x + mm*y == d
    if (d != 1) return -1;                         // to indicate failure
    // b*x + mm*y == 1, now apply (mod mm) to get b*x == 1 (mod mm)
    return (x + mm) % mm;                                // this is the answer
}

inline pair<int, int> hash_fast(int L, int R, vector<ll> &hh, vector<ll> &hh1) {
    if (R == -1) return {0, 0}; // for removing the first letter
    if (L == 0) return {hh[R], hh1[R]};                       // hh is the prefix hashes
    ll ans = 0, ans1 = 0;
    ans = ((hh[R] - hh[L - 1]) % M1 + M1) % M1;           // compute differences
    ans = ((ll) ans * modInverse(Pow1[L], M1)) % M1;   // remove P[L]^-1 (mod M1)
    ans1 = ((hh1[R] - hh1[L - 1]) % M2 + M2) % M2;           // compute differences
    ans1 = ((ll) ans1 * modInverse(Pow2[L], M2)) % M2;   // remove P[L]^-1 (mod M1)
    return {ans, ans1};
}

// mostly template code from book above. just edited a little to make it have 2 hash numbers, and work with dynamic data type vectors instead

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc;
    cin >> tc;
    n = 0;
    vector<string> words(tc);
    for (int i = 0; i < tc; i++) {
        cin >> words[i];
        n = max(n, (ll) words[i].size());
    }
    // put pow here so no need recompute
    Pow1.assign(n, 0);
    Pow2.assign(n, 0);
    Pow1[0] = 1;                                    // compute p^i % M1
    for (int i = 1; i < n; ++i)                    // O(n)
        Pow1[i] = (Pow1[i - 1] * p) % M1;
    Pow2[0] = 1;                                    // compute p1^i % M2
    for (int i = 1; i < n; ++i)                    // O(n)
        Pow2[i] = ((ll) Pow2[i - 1] * p1) % M2;
    // compute rolling rollingHashes
    vector<vector<ll>> rollingHashes1(tc), rollingHashes2(tc);
    unordered_set<pair<ll,ll>, pair_hash> dict; // store the hashes of the full word
    for (int i = 0; i < tc; i++) {
        T = words[i];
        n = T.size();
        h1.assign(n, 0);
        h2.assign(n, 0);
        computeRollingHash();
        for (int j = 0; j < n; j++) {
            rollingHashes1[i].push_back(h1[j]);
            rollingHashes2[i].push_back(h2[j]);
        }
        dict.insert({h1[n - 1], h2[n - 1]});
    }
    // check if a word missing a letter j is in dict
    int typo = 0;
    for (int i = 0; i < tc; i++) {
        for (int j = 0; j < words[i].size(); ++j) {
            // exclude the jth letter
            auto [a, b] = hash_fast(0, j - 1, rollingHashes1[i], rollingHashes2[i]); // hash of prefix
            auto [c, d] = hash_fast(j + 1, words[i].size() - 1, rollingHashes1[i], rollingHashes2[i]); // hash of suffix
            ll typoHash1 = a + c * Pow1[j];
            ll typoHash2 = b + d * Pow2[j];
            if (dict.find({typoHash1 % M1, typoHash2 % M2}) != dict.end()) {
                cout << words[i] << '\n';
                typo = 1;
                break;
            }
        }
    }
    if (!typo) cout << "NO TYPOS" << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

