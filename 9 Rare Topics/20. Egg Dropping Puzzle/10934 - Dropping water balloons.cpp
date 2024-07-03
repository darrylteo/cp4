#include <bits/stdc++.h>

using namespace std;

typedef __int128 i128;
typedef long long ll;

i128 nck(int n, int k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    i128 result = n;
    for (int i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

ll k, n;

i128 floors(int d) {
    i128 res = 0;
    for (int i = 1; i <= k; i++) res += nck(d, i);
    return res;
}

void solve() {
    for (int i = 1; i <= 63; ++i) {
        if (floors(i) >= n) {
            cout << i << '\n';
            return;
        }
    }
    cout << "More than 63 trials needed.\n";
}

// follow book formula for number of floors that can be tested with d drops and k eggs

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> k >> n, k) {
        solve();
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
