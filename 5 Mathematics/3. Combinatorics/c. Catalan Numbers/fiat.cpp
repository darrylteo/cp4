#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 100010;
const int p = 1e9+7; // p is a prime > MAX_N

ll modPow(ll a, ll x, ll p) {
    ll res = 1;
    while (x > 0) {
        if (x & 1) res = (res * a) % p;
        a = (a * a) % p;
        x >>= 1;
    }
    return res;
}

ll inv(ll a) { // Fermat’s little theorem
    return modPow(a, p-2, p); // modPow in Section 5.8
} // that runs in O(log p)

ll Cat[MAX_N];

// code direct from book
// btw picture looks very familiar. same as wikipedia

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nn;
    cin >> nn;
    Cat[0] = 1;
    for (int n = 0; n < MAX_N - 1; ++n) // O(MAX_N log p)
        Cat[n + 1] = ((4 * n + 2) % p * Cat[n] % p * inv(n + 2)) % p;
    cout << Cat[nn] << "\n"; // the answer is 945729344

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


