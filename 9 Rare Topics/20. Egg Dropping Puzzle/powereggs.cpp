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

ll k, n;
vector<vector<ll>> floordk(64, vector<ll>(64, 0));

ll floors(int d) {
    if (floordk[d][k] != 0) return floordk[d][k];
    ll res = 0;
    for (int i = 1; i <= k; i++) res += nck(d, i);
    return floordk[d][k] = res;
}

void solve() {
    for (int i = 1; i <= 32; ++i) {
        if (floors(i) >= n) {
            cout << i << '\n';
            return;
        }
    }
    cout << "Impossible\n";
}

// follow book formula for number of floors that can be tested with d drops and k eggs

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        solve();
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
