#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vull;
typedef pair<ull, ull> pull;

inline pull addFraction(pull f1, pull f2) {
    ull n1 = f1.first, d1 = f1.second;
    ull n2 = f2.first, d2 = f2.second;
    ull n = n1 * d2 + n2 * d1;
    ull d = d1 * d2;
    ull g = __gcd(n, d);
    return {n / g, d / g};
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        pull curr = {1, a[0]};
        for (int i = 1; i < n; ++i) {
            curr = addFraction(curr, {1, a[i]});
        }

        ull currN = curr.second * n, currD = curr.first;
        ull g = __gcd(currN, currD);
        currN /= g, currD /= g;
        cout << "Case " << cases << ": " << currN << "/" << currD << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

