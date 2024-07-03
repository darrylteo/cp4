#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull choose(int n, int k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    ull res = n;
    for (int i = 2; i <= k; i++) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

ull derange(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (n - 1) * (derange(n - 1) + derange(n - 2));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b) {
        ull ans = 0;
        // for each derangement. e.g. sample input 2: can either derange 4 or 3, so that 0 or 1 ppl come to the party
        for (int d = a; d >= a - b; --d) {
            ans += choose(a, d) * derange(d);
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
