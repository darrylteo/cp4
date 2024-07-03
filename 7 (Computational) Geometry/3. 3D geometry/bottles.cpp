#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

// using simpson's rule from: https://www.intmath.com/integration/6-simpsons-rule.php

ld poly[15]; // coefficients of the polynomial
int n; // degree of the polynomial
int p = 1e3; // number of intervals... surprised that 1e3 is enough

// returns square of f(x)
inline ld eval(ld x) {
    ld res = 0, xpow = 1; // important speed up. pow(x, i) is slow
    for (int i = 0; i <= n; i++) {
        res += poly[i] * xpow;
        xpow *= x;
    }
    return res * res;
}

inline ld getVol(ld a, ld b) {
    ld w = (b - a) / p;
    ld res = eval(a) + eval(b); // FIRST + LAST
    for (int i = 1; i < p; i += 2) {
        res += 4 * eval(a + i * w);
    }
    for (int i = 2; i < p; i += 2) {
        res += 2 * eval(a + i * w);
    }
    return res * w / 3 * M_PI;
}

// find the value of x such that the integral from left to x is V
inline ld BSTA(ld left, ld a, ld b, ld V) {
    ld m = (a + b) / 2;
    if (b - a < 1e-4) {
        return m;
    }
    ld val = getVol(left, m);
    if (val < V) {
        return BSTA(left, m, b, V);
    } else {
        return BSTA(left, a, m, V);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (cin >> n) {
        for (int i = 0; i <= n; i++) {
            cin >> poly[i];
        }
        ld a, b, V;
        cin >> a >> b >> V;
        cout << "Case " << cases++ << ": " << fixed << setprecision(2) << getVol(a, b) << '\n';
        if (getVol(a, b) < V) {
            cout << "insufficient volume\n";
        } else {
            ld start = a;
            vector<ld> ans;
            for (int i = 0; i < 8; ++i) {
                ld x = BSTA(a, a, b, V);
                if (x >= b - 1e-4) {
                    break;
                }
                ans.push_back(x-start);
                a = x;
            }
            for (int i = 0; i < ans.size(); ++i) {
                cout << fixed << setprecision(2) << ans[i];
                if (i + 1 < ans.size()) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}

