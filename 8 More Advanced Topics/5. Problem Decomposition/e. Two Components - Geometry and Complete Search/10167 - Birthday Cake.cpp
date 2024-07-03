#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;

    point(int x, int y) : x(x), y(y) {}
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    while (cin >> N, N) {
        vector<point> points;
        for (int i = 0; i < 2 * N; ++i) {
            int x, y;
            cin >> x >> y;
            points.emplace_back(x, y);
        }
        while (true) {
            int A = -500 + rand() % 1001; // [-500, 500]. speed up rather than try all
            int B = -500 + rand() % 1001;
            int cnt = 0;
            for (int i = 0; i < 2 * N; ++i) {
                point r = points[i];
                if (r.x * A + r.y * B > 0) { // ccw test with point (0,0) (x=-B, y=A)
                    cnt++;
                    if (cnt > N) break;
                }
            }
            if (cnt == N) {
                cout << A << " " << B << endl;
                break;
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
