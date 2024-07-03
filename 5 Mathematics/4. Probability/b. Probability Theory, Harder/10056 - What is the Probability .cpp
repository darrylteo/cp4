#include <bits/stdc++.h>

using namespace std;

// for 2 ppl
// P(p1 wins) = p + (1-p)^2 * p + (1-p)^4 * p + ... = p / (1 - (1-p)^2) = p / (2p - p^2) = 1 / (2 - p)
// P(p2 wins) = (1-p) * p + (1-p)^3 * p + (1-p)^5 * p + ... = (1-p) * P(p1 wins)

// for n ppl
// P(p1 wins) = p / (1 - (1-p)^n)
// P(p2 wins) = (1-p) * P(p1 wins)
// P(pn wins) = (1-p)^(n-1) * P(p1 wins)

double fastpow(double a, int b) {
    double res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, I;
        double p;
        cin >> n >> p >> I;
        if (p == 0) {
            cout << "0.0000\n";
            continue;
        }
        double ans = p / (1 - fastpow(1 - p, n));
        ans = ans * fastpow(1 - p, I - 1);
        cout << fixed << setprecision(4) << ans << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
