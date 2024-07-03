#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll extEuclid(ll a, ll b, ll &x, ll &y) { // pass x and y by ref
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) { // repeats until b == 0
        ll q = a/b;
        ll t = b; b = a%b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    return a; // returns gcd(a, b)
}

// use formula from book for Solving Linear Diophantine Equation

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll a, b, c1, c2, x, y, c;
    while (cin >> c >> c1 >> a >> c2 >> b, c) {
        ll d = extEuclid(a, b, x, y);
        if (c%d) {
            cout << "failed\n";
        } else {
            x *= c/d; y *= c/d;
            ll l = ceil(-1.0*x*d/b), r = floor(1.0*y*d/a);
            if (l > r) {
                cout << "failed\n";
            } else {
                // compare edges enough. in between cannot be better than edges.
                ll x1 = x+b/d*l, y1 = y-a/d*l;
                ll x2 = x+b/d*r, y2 = y-a/d*r;
                if (c1*x1+c2*y1 < c1*x2+c2*y2) {
                    cout << x1 << ' ' << y1 << '\n';
                } else {
                    cout << x2 << ' ' << y2 << '\n';
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


