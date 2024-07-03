#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    for (a = 2; a <= 200; ++a) {
        for (b = 2; b < a; ++b) {
            for (c = b + 1; c < a; ++c) {
                for (d = c + 1; d < a; ++d) {
                    if (a * a * a == b * b * b + c * c * c + d * d * d) {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << '\n';
                    }
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
