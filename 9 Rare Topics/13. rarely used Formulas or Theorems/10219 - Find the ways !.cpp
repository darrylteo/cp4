#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double nCk(ll n, ll k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return log10(1);

    double result = log10(n);
    for (ll i = 2; i <= k; ++i) {
        result += log10(n - i + 1);
        result -= log10(i);
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n, k;
    while (cin >> n >> k) {
        cout << (ll) nCk(n, k) + 1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

