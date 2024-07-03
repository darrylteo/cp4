#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// g(0) = 0
// g(1) = 0
// g(2) = 1
// g(3) = 0
// g(4) = 2
// g(5) = 1
// g(6) = 3 // to get this, take mex{g(5), g(4), g(3)} = mex{1, 2, 0} = 3
// g(7) = 0
// g(8) = 4
// g(9) = 2
// g(10) = 5
// g(11) = 1 // to get this, take mex{g(10), g(9), g(8), g(7), g(6)} = mex{5, 2, 4, 0, 3} = 1 <- this is also g(5) since it's excluded for g(11), but included for g(12)
// g(12) = 6

ll getGrundy(ll u) {
    if (u == 1 || u == 0) return 0;
    if (u & 1) return getGrundy(u / 2LL);
    return u / 2LL;
}

ll getNimSum(const vll &pile) {
    ll nim = 0;
    for (auto &p: pile) nim ^= p;
    return nim;
}

// code from book

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vll pile(n);
        for (int i = 0; i < n; ++i) {
            cin >> pile[i];
            pile[i] = getGrundy(pile[i]);
        }
        ll nim = getNimSum(pile);
        if (nim) cout << "YES\n";
        else cout << "NO\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

