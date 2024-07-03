#include <bits/stdc++.h>

using namespace std;

// after testing long double, double and float, the speed difference is huge in kattis! 0.8s, 0.2s, 0.1s
// note i do not get such dramatic speed up in clion
typedef float ld;

// code from book
#define EARTH_RAD (6371009) // in meters
inline ld gcDist(ld pLa, ld pLo, ld qLa, ld qLo, ld r) {
    pLa *= M_PI / 180;
    pLo *= M_PI / 180; // degree to radian
    qLa *= M_PI / 180;
    qLo *= M_PI / 180;
    return r * acos(cos(pLa) * cos(pLo) * cos(qLa) * cos(qLo) +
                    cos(pLa) * sin(pLo) * cos(qLa) * sin(qLo) + sin(pLa) * sin(qLa));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<pair<ld, ld>> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        vector<ld> worst(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ld dist = gcDist(points[i].first, points[i].second, points[j].first, points[j].second, EARTH_RAD);
                worst[i] = max(worst[i], dist);
                worst[j] = max(worst[j], dist);
            }
        }
        ld best = 1e18;
        int bestIdx = -1;
        for (int i = 0; i < n; i++) {
            if ((worst[i] - best) < 1e-9) {
                best = worst[i];
                bestIdx = i;
            }
        }
        cout << fixed << setprecision(2) << points[bestIdx].first << " " << points[bestIdx].second << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}

