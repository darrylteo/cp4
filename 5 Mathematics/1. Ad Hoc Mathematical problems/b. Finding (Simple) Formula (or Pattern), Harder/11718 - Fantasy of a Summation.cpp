#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// there will be n^k sums of k terms each.
// each term will appear (n^k)*k/n = (n^(k-1))*k times
// fast modpow: https://stackoverflow.com/questions/8496182/calculating-powa-b-mod-n

template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n, k, mod;
        cin >> n >> k >> mod;
        ll ans = 0, factor = 1;
        factor = modpow(n, k - 1, mod);
        factor = (factor * k) % mod;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ans = (ans + x * factor) % mod;
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


