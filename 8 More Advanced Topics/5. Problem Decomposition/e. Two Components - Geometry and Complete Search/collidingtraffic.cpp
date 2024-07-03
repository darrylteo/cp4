#include <bits/stdc++.h>

using namespace std;

// s is diff in displacement, v is diff in velocity, t is time
// sx = sx_0 + vx_t * t
// sy = sy_0 + vy_t * t
// if sx^2 + sy^2 = r^2 exists. find time.
// sx_0^2 + sx_0*vx_t*t + vx_t^2*t^2 + sy_0^2 + sy_0*vy_t*t + vy_t^2*t^2 = r^2
// a = vx_t^2 + vy_t^2
// b = 2 * (sx_0*vx_t + sy_0*vy_t)
// c = sx_0^2 + sy_0^2 - r^2

struct boat {
    double x, y, d, s;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        double r;
        cin >> n >> r;
        vector<boat> boats(n);
        for (int i = 0; i < n; i++) {
            cin >> boats[i].x >> boats[i].y >> boats[i].d >> boats[i].s;
            boats[i].d = boats[i].d * M_PI / 180;
        }
        int ans = 1e9, found = 0;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double sx_0 = boats[j].x - boats[i].x, sy_0 = boats[j].y - boats[i].y;
                if (sx_0 * sx_0 + sy_0 * sy_0 <= r * r) {
                    ans = 0;
                    found = 1;
                    break;
                }
                // sin for x since given angle from NORTH
                double vx_t = boats[j].s * sin(boats[j].d) - boats[i].s * sin(boats[i].d);
                double vy_t = boats[j].s * cos(boats[j].d) - boats[i].s * cos(boats[i].d);
                double a = vx_t * vx_t + vy_t * vy_t;
                double b = 2 * (sx_0 * vx_t + sy_0 * vy_t);
                double c = sx_0 * sx_0 + sy_0 * sy_0 - r * r;
                double disc = b * b - 4 * a * c;
                if (disc < 0 || a == 0) continue;
                double t = (-b - sqrt(disc)) / (2 * a);
                if (t >= 0) {
                    ans = min(ans, (int) round(t));
                } else {
                    t = (-b + sqrt(disc)) / (2 * a);
                    if (t >= 0) {
                        ans = min(ans, (int) round(t));
                    }
                }
            }
        }
        if (ans == 1e9) cout << "No collision.\n";
        else cout << ans << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
