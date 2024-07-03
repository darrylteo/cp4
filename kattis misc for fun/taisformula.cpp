#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long double ans = 0, t, v, tt, vv;
    cin >> n >> t >> v;
    n--;
    while (n--) {
        cin >> tt >> vv;
        ans += (long double) (v + vv) * (tt - t) / 2;
        t = tt;
        v = vv;
    }
    cout << fixed << setprecision(10) << ans / 1000 << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
