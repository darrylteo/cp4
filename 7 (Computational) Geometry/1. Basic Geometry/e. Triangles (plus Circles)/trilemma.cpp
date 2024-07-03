#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Case #" << cases << ": ";
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        vector<double> sides;
        sides.push_back(hypot(x1 - x2, y1 - y2));
        sides.push_back(hypot(x2 - x3, y2 - y3));
        sides.push_back(hypot(x3 - x1, y3 - y1));
        sort(sides.begin(), sides.end());
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c) {
            cout << "not a triangle\n";
            continue;
        }

        if (a != b && b != c && c != a) cout << "scalene ";
        else cout << "isosceles ";

        if (fabs(a * a + b * b - c * c) < 1e-9) cout << "right triangle\n";
        else if (a * a + b * b > c * c) cout << "acute triangle\n";
        else cout << "obtuse triangle\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}