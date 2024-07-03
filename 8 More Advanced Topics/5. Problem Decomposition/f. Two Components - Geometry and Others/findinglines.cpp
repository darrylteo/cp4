#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
};

// high percent of points lie on line so high chance we land on correct line anyway

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    srand(time(0));

    int n, p;
    cin >> n >> p;
    if (n == 1) {
        cout << "possible\n";
        return 0;
    }
    int need = ceil(n * p / 100.0);
    vector<point> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

    for (int tr = 0; tr < 500; ++tr) {
        int i = rand() % n;
        int j = rand() % n;
        if (i == j) continue;
        int cnt = 0;
        if (points[i].x == points[j].x) {
            for (int k = 0; k < n; ++k) {
                if (points[k].x == points[i].x) {
                    cnt++;
                    if (cnt >= need) {
                        cout << "possible\n";
                        return 0;
                    }
                }
            }
        } else if (points[i].y == points[j].y) {
            for (int k = 0; k < n; ++k) {
                if (points[k].y == points[i].y) {
                    cnt++;
                    if (cnt >= need) {
                        cout << "possible\n";
                        return 0;
                    }
                }
            }
        } else {
            long long dy = points[j].y - points[i].y;
            long long dx = points[j].x - points[i].x;
            long long gcdd = __gcd(dy, dx);
            dy /= gcdd;
            dx /= gcdd;
            long long c = points[i].y * dx - points[i].x * dy;
            for (int k = 0; k < n; ++k) {
                if (points[k].y * dx == points[k].x * dy + c) {
                    cnt++;
                    if (cnt >= need) {
                        cout << "possible\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "impossible\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}