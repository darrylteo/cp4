#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int l, w, a;
        cin >> l >> w >> a;
        double h = tan(a * M_PI / 180) * l;
        double A = sqrt(l * l + h * h); // line A on diagram
        int reflect = ((int) (h / w) % 2 && h > w);
        while (h > w) h = h - w;
        if (reflect) {
            h = w - h;
        }
        double B = sqrt(l * l + h * h); // line B on diagram
        cout << fixed << setprecision(3) << A / B << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}