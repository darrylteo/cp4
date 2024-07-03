#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;

// go plot graph and see
// eqn of top block - bottom block, will have min point when they touch and max at max separation
// ans = max - min
// dy/dx to find max and min points. and don't forget boundary points 0, 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double x;
    while (cin >> x) {
        vd coefs(4);
        coefs[0] = x;
        for (int i = 1; i < 4; i++) {
            cin >> coefs[i];
        }
        for (int i = 0; i < 4; i++) {
            cin >> x;
            coefs[i] -= x;
        }
        double a, b, c;
        a = coefs[3] * 3;
        b = coefs[2] * 2;
        c = coefs[1];
        vd candidates = {0, 1};
        double discr = b * b - 4 * a * c;
        if (discr > 0) {
            candidates.push_back((-b + sqrt(discr)) / (2 * a));
            candidates.push_back((-b - sqrt(discr)) / (2 * a));
        }
        double mini = 1e9, maxi = -1e9;
        for (double can : candidates) {
            if (can >= 0 && can <= 1) {
                double y = coefs[0] + coefs[1] * can + coefs[2] * can * can + coefs[3] * can * can * can;
                mini = min(mini, y);
                maxi = max(maxi, y);
            }
        }
        cout << fixed << setprecision(9) << maxi - mini << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

