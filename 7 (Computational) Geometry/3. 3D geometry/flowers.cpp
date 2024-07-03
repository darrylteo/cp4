#include <bits/stdc++.h>

using namespace std;

typedef double ld;

int p = 6e4; // number of intervals... after testing this is somewhat optimal (able to 0.00s)
ld a, b, h;

// returns square of f(x)
inline ld eval(ld x) {
    ld res = a * exp(-x * x) + b * sqrt(x);
    return res * res;
}

inline ld getVol(ld l, ld r) {
    ld w = (r - l) / p;
    ld res = eval(l) + eval(r); // FIRST + LAST
    for (int i = 1; i < p; i += 2) {
        res += 4 * eval(l + i * w);
    }
    for (int i = 2; i < p; i += 2) {
        res += 2 * eval(l + i * w);
    }
    return res * w / 3 * M_PI;
}

// using simpson's rule from: https://www.intmath.com/integration/6-simpsons-rule.php
// i find it odd that this qn 5.9 difficulty but the bottles one was harder and 3.0 difficulty

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ld V;
    int N;
    cin >> V >> N;
    ld best = 1e18;
    int bestIdx = -1;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> h;
        ld currVol = getVol(0, h);
        if (fabs(currVol - V) < best) {
            best = fabs(currVol - V);
            bestIdx = i;
        }
    }
    cout << bestIdx << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
