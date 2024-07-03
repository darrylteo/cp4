#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// can write down and figure out formula or...
// i just take formula from wiki page of mortgage calculator

double exPow(double base, ll exp) {
    double result = 1;
    while (exp > 0) {
        if (exp & 1) result = result * base;
        base = base * base;
        exp >>= 1;
    }
    return result;
}

// X = principal, Y = repayment per period, N = number of periods, r = interest rate per period (decimal)
double amtOwed(ll X, ll Y, ll N, double r) {
    return X * exPow(1 + r, N) - Y * (exPow(1 + r, N) - 1) / r;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll X, Y, N;
    double r;
    while (cin >> X >> Y >> N >> r) {
        if (X == 0 && Y == 0 && N == 0 && r == 0) break;

        N *= 12;
        r /= 1200;
        if (r == 0) {
            if (X <= Y*N) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if (amtOwed(X, Y, N, r) <= 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


