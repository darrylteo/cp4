#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, k;
    while (cin >> N >> M >> k, N) {
        k++; N++;
        vector<ll> P(k);
        for (int i = 0; i < k; i++) cin >> P[i];
        unordered_set<ll> s;
        for (int i = 0; i <= M; i++) {
            ll x = 0;
            for (int j = 0; j < k; j++) {
                x += P[j] * modpow(i, j, N);
                x %= N;
            }
            s.insert(x);
        }
        cout << s.size() << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
