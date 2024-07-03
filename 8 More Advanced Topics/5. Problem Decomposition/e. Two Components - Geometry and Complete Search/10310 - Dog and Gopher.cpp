#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n;
    while (cin >> n) {
        point dog{}, gopher{};
        cin >> gopher.x >> gopher.y >> dog.x >> dog.y;
        if (n == 0) {
            cout << "The gopher cannot escape.\n";
            continue;
        }
        vector<point> holes;
        double x, y;
        while (n--) {
            cin >> x >> y;
            holes.push_back({x, y});
        }
        vector<double> dogDist, gopherDist;
        for (auto &hole : holes) {
            dogDist.push_back((hole.x - dog.x) * (hole.x - dog.x) + (hole.y - dog.y) * (hole.y - dog.y));
            gopherDist.push_back((hole.x - gopher.x) * (hole.x - gopher.x) + (hole.y - gopher.y) * (hole.y - gopher.y));
        }
        int found = 0;
        for (int i = 0; i < holes.size(); i++) {
            if (gopherDist[i] * 4 - dogDist[i] < 1e-6) {
                cout << fixed << setprecision(3) << "The gopher can escape through the hole at (" << holes[i].x << "," << holes[i].y << ").\n";
                found = 1;
                break;
            }
        }
        if (!found) cout << "The gopher cannot escape.\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
