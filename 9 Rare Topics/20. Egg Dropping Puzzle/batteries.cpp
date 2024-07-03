#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nck(int n, int k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    ll result = n;
    for (int i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

ll k = 2, n;
vector<ll> floordk(500, 0);

ll floors(int d) {
    if (floordk[d] != 0) return floordk[d];
    ll res = 0;
    for (int i = 1; i <= k; i++) res += nck(d, i);
    return floordk[d] = res;
}

void solve() {
    for (int i = 0; i <= 500; ++i) {
        if (floors(i) >= n - 1) { // from sample input seems like need to minus 1
            cout << i << '\n';
            return;
        }
    }
}

// given n as input, and k = 2, find number of drops under worst case scenario

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> n, n) {
        solve();
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
