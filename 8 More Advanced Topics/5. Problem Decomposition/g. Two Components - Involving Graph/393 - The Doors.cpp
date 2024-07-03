#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
};

struct seg {
    double x, b, t; // x, bottom and top
};

// we need adj for each point to any point on right side of it.
// must check if there is a wall between them.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cham;
    while (cin >> cham, cham != -1) {
        vector<seg> segs; // record all segs in each x.
        vector<point> points; // record all points which are start, end, tips of segs.
        points.push_back({0, 5});

        for (int i = 0; i < cham; i++) {
            double x, y, y1;
            cin >> x >> y;
            segs.push_back({x, 0, y});
            points.push_back({x, y});
            cin >> y >> y1;
            points.push_back({x, y});
            points.push_back({x, y1});
            segs.push_back({x, y, y1});
            cin >> y;
            points.push_back({x, y});
            segs.push_back({x, y, 10});
        }
        points.push_back({10, 5});

        double adj[points.size()][points.size()];
        for (int i = 0; i < points.size(); i++) for (int j = 0; j < points.size(); j++) adj[i][j] = 1e9;
        for (int i = 0; i < points.size(); i++) adj[i][i] = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i].x == points[j].x) continue; // don't move vertically
                double xStart = points[i].x, xEnd = points[j].x;
                // check all segs between (exclusive) xStart and xEnd,
                // that if we draw a line from points[i] to points[j] it will intersect with any of these segs.
                double m = (points[j].y - points[i].y) / (points[j].x - points[i].x);
                double c = points[i].y - m * points[i].x;
                // sub in the 'x' of the segs and check if the 'y' is in the range of the seg.
                bool intersect = false;
                for (auto & s : segs) {
                    if (s.x <= xStart || s.x >= xEnd) continue;
                    double y = m * s.x + c;
                    if (y >= s.b && y <= s.t) {
                        intersect = true;
                        break;
                    }
                }
                if (!intersect) adj[i][j] = hypot(points[j].x - points[i].x, points[j].y - points[i].y);
            }
        }

        // floyd warshall
        for (int k = 0; k < points.size(); k++) {
            for (int i = 0; i < points.size(); i++) {
                for (int j = 0; j < points.size(); j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        cout << fixed << setprecision(2) << adj[0][points.size() - 1] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}