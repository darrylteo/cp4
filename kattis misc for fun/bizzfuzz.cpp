#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll a, b, c, d, e;
    cin >> a >> b >> c >> d;
    e = lcm(c, d);
    if (a % e) a += e - a % e; // push a to the next multiple of e
    if (a > b) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1; // a is already a multiple of e
    ans += (b - a) / e;
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
