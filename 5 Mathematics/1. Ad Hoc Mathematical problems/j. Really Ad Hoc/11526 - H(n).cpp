#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// werid formula from https://blog.csdn.net/synapse7/article/details/12873437

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        ll ans = 0;
        int r = sqrt(n);
        for (int i = 1; i <= r; i++) {
            ans += n / i;
        }
        ans = 2 * ans - r * r;
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

