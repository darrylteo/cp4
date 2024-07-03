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

// use formula from book for Solving Linear Diophantine Equation
// more or less same as uva 10090 - Marbles

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll a, b, x, y, c;
    double tmpC, tmpA, tmpB;
    cin >> tmpC >> tmpA >> tmpB;
    a = tmpA * 100 + 1e-9;
    b = tmpB * 100 + 1e-9;
    c = tmpC * 100 + 1e-9;
    ll d = extEuclid(a, b, x, y);
    if (c % d) {
        cout << "none\n";
    } else {
        x *= c / d;
        y *= c / d;
        ll l = ceil(-1.0 * x * d / b), r = floor(1.0 * y * d / a);
        if (l > r) {
            cout << "none\n";
        } else {
            for (ll i = l; i <= r; ++i) {
                ll x1 = x + b / d * i, y1 = y - a / d * i;
                cout << x1 << " " << y1 << '\n';
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


