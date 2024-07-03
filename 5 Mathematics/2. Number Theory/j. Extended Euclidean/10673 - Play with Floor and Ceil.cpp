#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll extEuclid(ll a, ll b, ll &x, ll &y) { // pass x and y by ref
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) { // repeats until b == 0
        ll q = a / b;
        ll t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a; // returns gcd(a, b)
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll c, tmp2, a, b, x, y;
        cin >> c >> tmp2;
        a = (c / tmp2);
        b = ceil((1.0 * c / tmp2));
        ll d = extEuclid(a, b, x, y);
        cout << x * c / d << " " << y * c / d << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


