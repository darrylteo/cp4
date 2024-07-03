#include <bits/stdc++.h>

using namespace std;

const double INF = 1e9;
const double EPS = 1e-9;

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

// struct point_i { int x, y; };                 // minimalist mode

struct point_i {
    int x, y;                                      // use this if possible
    point_i() { x = y = 0; }                       // default constructor
    point_i(int _x, int _y) : x(_x), y(_y) {}      // constructor
};

struct point {
    double x, y;                                   // if need more precision
    point() { x = y = 0.0; }                       // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}  // constructor
    bool operator<(point other) const {          // override < operator
        if (fabs(x - other.x) > EPS)                   // useful for sorting
            return x < other.x;                        // by x-coordinate
        return y < other.y;                          // if tie, by y-coordinate
    }

    // use EPS (1e-9) when testing equality of two floating points
    bool operator==(point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

double dist(point p1, point p2) {                // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);            // return double
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);                // convert to radian
    return {p.x * cos(rad) - p.y * sin(rad),
            p.x * sin(rad) + p.y * cos(rad)};
}

// code from book website

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
        vector<point> points1(n), points2(n);
        for (int i = 0; i < n; ++i) {
            cin >> points1[i].x >> points1[i].y;
        }
        for (int i = 0; i < n; ++i) {
            cin >> points2[i].x >> points2[i].y;
        }
        sort(points1.begin(), points1.end());
        sort(points2.begin(), points2.end());
        if (points1 == points2) {
            cout << "MATCHED\n";
            continue;
        }

        // rotate points1
        int found = 0;
        for (int j = 90; j <= 360; j += 90) {
            vector<point> temp(n);
            for (int i = 0; i < n; ++i) {
                temp[i] = rotate(points1[i], j);
            }
            sort(temp.begin(), temp.end());
            // translate temp to match points2 first point
            double transX = points2[0].x - temp[0].x;
            double transY = points2[0].y - temp[0].y;
            for (int i = 0; i < n; ++i) {
                temp[i].x += transX;
                temp[i].y += transY;
            }
            if (temp == points2) {
                found = 1;
                break;
            }
        }
        if (found) cout << "MATCHED\n";
        else cout << "NOT MATCHED\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}