#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vll;

// exponentiation by squaring
ll powll(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

// lame pow loss of accuracy

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll x;
    string buf;
    while (getline(cin, buf)) {
        x = stoll(buf);
        getline(cin, buf);
        stringstream ss(buf);
        vll coefs;
        ll coef;
        while (ss >> coef) {
            coefs.push_back(coef);
        }
        ll ans = 0;
        for (int i = 0; i < coefs.size() - 1; i++) {
            ans += powll(x, coefs.size() - i - 2) * coefs[i] *  (coefs.size() - i - 1);
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

