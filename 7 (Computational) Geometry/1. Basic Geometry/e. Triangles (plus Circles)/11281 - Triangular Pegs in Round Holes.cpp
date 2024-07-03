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

    int M;
    cin >> M;
    vector<double> holes(M);
    for (int i = 0; i < M; ++i) cin >> holes[i];
    int N;
    cin >> N;
    vector<double> diameters(N);
    for (int i = 0; i < N; ++i) {
        vector<double> sideLengths(3);
        for (int j = 0; j < 3; ++j) cin >> sideLengths[j];
        sort(sideLengths.begin(), sideLengths.end());
        double a = sideLengths[0], b = sideLengths[1], c = sideLengths[2];
        if (a*a + b*b < c*c) {
            diameters[i] = c;
        } else {
            diameters[i] = 2 * a * b * c / sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a));
        }
    }
    for (int i = 0; i < N; ++i) {
        vector<int> fit;
        for (int j = 0; j < M; ++j) {
            if (holes[j] >= diameters[i]) {
                fit.push_back(j);
            }
        }
        if (fit.empty()) {
            cout << "Peg " << (char) (i + 'A') << " will not fit into any holes\n";
        } else {
            cout << "Peg " << (char) (i + 'A') << " will fit into hole(s):";
            for (int j : fit) {
                cout << " " << j + 1;
            }
            cout << "\n";
        }
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}