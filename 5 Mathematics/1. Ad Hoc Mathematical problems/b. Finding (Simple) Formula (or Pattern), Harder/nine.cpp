#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

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

    int T; cin >> T;
    ll d, mod = 1e9 + 7, base = 9;
    while (T--) {
        cin >> d;
        ll ans = 8 * modpow(base, d - 1, mod);
        cout << ans % mod << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


