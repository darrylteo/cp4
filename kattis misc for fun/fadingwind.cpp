#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, k, v, s;
    cin >> h >> k >> v >> s;
    int ans = 0;
    while (h > 0) {
        v += s;
        v -= max(1, v/10);
        if (v >= k) {
            h++;
        } else if (v > 0) {
            h--;
            if (h == 0) {
                v = 0;
            }
        } else {
            h = 0;
            v = 0;
        }
        ans += v;
        if (s > 0) {
            s--;
        }
    }
    cout << ans << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

