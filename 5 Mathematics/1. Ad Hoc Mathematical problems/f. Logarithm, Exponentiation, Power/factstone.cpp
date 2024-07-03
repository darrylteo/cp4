#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// 2^Y >= n!
// BITS >= log2(1) + log2(2) + ... + log2(n)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<double> v(260000);
    v[0] = 0;
    for (int i = 1; i < 260000; i++) {
        v[i] = v[i - 1] + log2(i);
    }

    int n;
    while (cin >> n, n) {
        int bits = pow(2, (n - 1960)/10 + 2); // it doubles at 10 year mark, not continuous increase
        int ans = lower_bound(v.begin(), v.end(), bits) - v.begin() - 1;
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

