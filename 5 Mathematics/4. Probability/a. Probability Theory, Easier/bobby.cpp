#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nCk(ll n, ll k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    ll result = n;
    for (ll i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

double binomcdf(int n, int k, double p) {
    double cdf = 0.0;
    for (int i = 0; i <= k; i++) {
        cdf += (double) nCk(n, i) * pow(p, i) * pow(1 - p, n - i);
    }
    return cdf;
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
        int R, S, X, Y, W;
        cin >> R >> S >> X >> Y >> W;
        double p = (double) (S - R + 1) / S; // probability of winning this roll
        double bobbyLose = binomcdf(Y, X - 1, p); // chance to get win less than X rolls
        if ((1 - bobbyLose) * W <= 1) {
            cout << "no" << '\n';
        } else {
            cout << "yes" << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


