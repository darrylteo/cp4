#include <bits/stdc++.h>

using namespace std;

struct platform {
    int l, r, h;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<platform> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].h >> p[i].l >> p[i].r;
    sort(p.begin(), p.end(), [](const platform &a, const platform &b) {
        return a.h > b.h;
    });
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = p[i].l, r = p[i].r, h = p[i].h;
        int foundLeft = 0, foundRight = 0;
        for (int j = i + 1; j < n; j++) {
            if (!foundLeft && p[j].l <= l && p[j].r >= l + 1 && p[j].h < h) {
                foundLeft = 1;
                ans += h - p[j].h;
            }
            if (!foundRight && p[j].l <= r - 1 && p[j].r >= r && p[j].h < h) {
                foundRight = 1;
                ans += h - p[j].h;
            }
        }
        if (!foundLeft) ans += h;
        if (!foundRight) ans += h;
    }
    cout << ans << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}