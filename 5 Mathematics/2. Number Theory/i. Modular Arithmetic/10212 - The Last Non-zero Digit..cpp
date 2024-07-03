#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        ll ans = 1;
        for (int i = n; i >= n - m + 1; --i) {
            ans *= i;
            while (ans % 10 == 0) ans /= 10;
            ans %= 1000000000;
        }
        cout << ans % 10 << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


