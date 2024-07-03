#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define big 1000000000

inline ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
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
        int n, x;
        ll ans = 1;
        cin >> n;
        while (n--) {
            cin >> x;
            if (ans <= big) {
                ans = lcm(ans, x);
            }
        }
        if (ans > big) {
            cout << "More than a billion." << '\n';
        } else {
            cout << ans << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}