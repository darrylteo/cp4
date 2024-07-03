#include <bits/stdc++.h>

using namespace std;

// not hard for a hard kattis rating. just some high school math/physics

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<string, string>> v(n);
        string missingCmd;
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            if (v[i].second == "?") missingCmd = v[i].first;
        }
        // if it is a moving command we check all commands and calculate direction of missing command
        if (missingCmd == "fd" || missingCmd == "bk") {
            double x = 0, y = 0, a = 0, aMis; // x, y, angle, angle just before moving command
            for (int i = 0; i < n; i++) {
                double val = 0;
                if (v[i].second != "?") val = stod(v[i].second);
                else {
                    aMis = a;
                    continue;
                }

                if (v[i].first == "fd") {
                    x += val * cos(a);
                    y += val * sin(a);
                } else if (v[i].first == "bk") {
                    x -= val * cos(a);
                    y -= val * sin(a);
                } else if (v[i].first == "lt") {
                    a += val * M_PI / 180;
                } else if (v[i].first == "rt") {
                    a -= val * M_PI / 180;
                }
            }
            if (fabs(sin(aMis)) < 1e-9) cout << abs(x) << "\n";
            else if (fabs(cos(aMis)) < 1e-9) cout << abs(y) << "\n";
            else cout << abs(round(y / sin(aMis))) << "\n";
        }
            // if it is a turning command we check all commands before, and after then test all angles between 0 and 359
        else {
            double x = 0, y = 0, x2 = 0, y2 = 0, a = 0, aMis; // x, y for before '?', x2, y2 for after '?', angle, angle just before turning command
            int before = 1;
            for (int i = 0; i < n; i++) {
                double val = 0;
                if (v[i].second != "?") val = stod(v[i].second);
                else {
                    aMis = a;
                    before = 0;
                    continue;
                }

                if (v[i].first == "fd") {
                    if (before) {
                        x += val * cos(a);
                        y += val * sin(a);
                    } else {
                        x2 += val * cos(a);
                        y2 += val * sin(a);
                    }
                } else if (v[i].first == "bk") {
                    if (before) {
                        x -= val * cos(a);
                        y -= val * sin(a);
                    } else {
                        x2 -= val * cos(a);
                        y2 -= val * sin(a);
                    }
                } else if (v[i].first == "lt") {
                    a += val * M_PI / 180;
                } else if (v[i].first == "rt") {
                    a -= val * M_PI / 180;
                }
            }
            double best = 1e9, bestAngle = 0;
            for (int i = 0; i < 360; i++) {
                double a2 = i * M_PI / 180;
                double xx = x + x2 * cos(a2) - y2 * sin(a2);
                double yy = y + x2 * sin(a2) + y2 * cos(a2);
                if (abs(xx) + abs(yy) < best) {
                    best = abs(xx) + abs(yy);
                    bestAngle = i;
                }
            }
            if (missingCmd == "lt" || bestAngle == 0) cout << bestAngle << "\n";
            else cout << 360 - bestAngle << "\n";
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}