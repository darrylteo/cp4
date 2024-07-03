#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

struct point_i {
    int x, y;                                      // use this if possible
    point_i() { x = y = 0; }                       // default constructor
    point_i(int _x, int _y) : x(_x), y(_y) {}      // constructor
};

struct point {
    double x, y;                                   // if need more precision
    point() { x = y = 0.0; }                       // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}  // constructor
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);                // convert to radian
    return {p.x * cos(rad) - p.y * sin(rad),
            p.x * sin(rad) + p.y * cos(rad)};
}

// assumption: the required points/lines functions have been written
// returns 1 if there is a circumCenter center, returns 0 otherwise
// if this function returns 1, ctr will be the circumCircle center
// and r is the same as rCircumCircle
int circumCircle(point p1, point p2, point p3, point &ctr, double &r) {
    double a = p2.x - p1.x, b = p2.y - p1.y;
    double c = p3.x - p1.x, d = p3.y - p1.y;
    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
    if (fabs(g) < EPS) return 0;

    ctr.x = (d * e - b * f) / g;
    ctr.y = (a * f - c * e) / g;
    r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
    return 1;
}

// code from book website

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n, cases = 1;
    while (cin >> n, n) {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        point p1(x1, y1), p2(x2, y2), p3(x3, y3);
        point ctr; // remember this
        double r;
        circumCircle(p1, p2, p3, ctr, r); // assume this is true
        // get all points by rotating around origin (by translating everything wrt origin)
        vector<point> points;
        point p = p1;
        p.x -= ctr.x;
        p.y -= ctr.y;
        points.push_back(p);
        double inc = 360.0 / n;
        for (int i = 1; i < n; i++) {
            p = rotate(p, inc);
            points.push_back(p);
        }
        // get max and min x and y
        double minX = 1e9, minY = 1e9, maxX = -1e9, maxY = -1e9;
        for (auto &point: points) {
            point.x += ctr.x;
            point.y += ctr.y;
            minX = min(minX, point.x);
            minY = min(minY, point.y);
            maxX = max(maxX, point.x);
            maxY = max(maxY, point.y);
        }
        // print area of rectangle
        cout << "Polygon " << cases++ << ": " << fixed << setprecision(3) << (maxX - minX) * (maxY - minY) << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}