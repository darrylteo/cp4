#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// ref: https://www.cnblogs.com/chunlvxiong/p/7537980.html

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int xa = sqrt(a);
        if (xa * xa == a) xa--;
        int ya = a - xa * xa;
        xa++;
        int xb = sqrt(b);
        if (xb * xb == b) xb--;
        int yb = b - xb * xb;
        xb++;
        int ans = 0;
        if (ya & 1) { // odd means pointing up triangle. if same row, move left/right else down
            if (xa == xb) {
                cout << yb - ya << endl;
            } else {
                xa++, ya++, ans++;
            }
        }
        if (!(ya & 1)) {
            ans += (xb - xa) * 2; // go down to same layer as target
            int Max1 = ya, Max2 = ya + (xb - xa) * 2; // min and max y value in same layer
            if (Max1 <= yb && yb <= Max2) { // if target is an up triangle
                if (yb & 1) ans++;
            } else if (yb < Max1) { // move left to target
                ans += Max1 - yb;
            } else { // move right to target
                ans += yb - Max2;
            }
            cout << ans << endl;
        }
        if (T) cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

