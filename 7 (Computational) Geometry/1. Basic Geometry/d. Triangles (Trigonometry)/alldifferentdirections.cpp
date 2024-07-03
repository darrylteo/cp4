#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n >> ws, n) {
        string buf;
        vector<pair<double, double>> points;
        // get dest of each person
        for (int i = 0; i < n; i++) {
            getline(cin, buf);
            double x, y, angle;
            stringstream ss(buf);
            ss >> x >> y;
            string cmd;
            double mag;
            ss >> cmd >> mag; // start direction
            angle = mag;
            while (ss >> cmd >> mag) {
                if (cmd == "turn") {
                    angle += mag;
                } else {
                    x += mag * cos(angle * M_PI / 180);
                    y += mag * sin(angle * M_PI / 180);
                }
            }
            points.emplace_back(x, y);
        }
        // get avg of all points
        double x = 0, y = 0;
        for (auto &p : points) {
            x += p.first;
            y += p.second;
        }
        x /= n;
        y /= n;
        // get worst dist
        double worst = 0;
        for (auto &p : points) {
            worst = max(worst, hypot(p.first - x, p.second - y));
        }
        cout << fixed << setprecision(4) << x << " " << y << " " << worst << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}