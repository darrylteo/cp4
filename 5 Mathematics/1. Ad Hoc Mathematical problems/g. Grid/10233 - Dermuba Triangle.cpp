#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

// looks straightforward, but getting circumcenter must be careful (esp with ints and doubles and ll since we increment)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll a, b;
    while (cin >> a >> b) {
        a++;
        b++;
        if (a > b) swap(a, b);
        ll xa = sqrt(a);
        if (xa * xa == a) xa--;
        ll ya = a - xa * xa;
        xa++;
        ll xb = sqrt(b);
        if (xb * xb == b) xb--;
        ll yb = b - xb * xb;
        xb++;

        // height of triangle = \sqrt{3} / 2
        // height to circumcenter = \sqrt{3} / 6 (if triangle point up)
        // other height to circumcenter = \sqrt{3} / 3 (if triangle point down)
        double base = (double) abs(yb - (ya + xb - xa)) / 2;
        double height = (double) (xb - xa - 1) * sqrt(3) / 2;
        // add the little bits
        if (ya % 2 == 0) {
            height += sqrt(3) / 3;
        } else {
            height += sqrt(3) / 6;
        }
        if (yb % 2 == 0) {
            height += sqrt(3) / 6;
        } else {
            height += sqrt(3) / 3;
        }
        // output answer
        double ans = hypot(base, height);
        cout << fixed << setprecision(3) << ans << '\n';


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

