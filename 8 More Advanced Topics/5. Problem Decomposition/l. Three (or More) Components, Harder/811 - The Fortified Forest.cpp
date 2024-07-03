#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-9;

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

struct point {
    double x, y;   // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator==(point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }

    bool operator<(const point &p) const {
        return x < p.x || (abs(x - p.x) < EPS && y < p.y);
    }
};

struct vec {
    double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

double dist(point p1, point p2) {                // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y);
}               // return double

// returns the perimeter of polygon P, which is the sum of
// Euclidian distances of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {       // by ref for efficiency
    double ans = 0.0;
    for (int i = 0; i < (int) P.size() - 1; ++i)      // note: P[n-1] = P[0]
        ans += dist(P[i], P[i + 1]);                   // as we duplicate P[0]
    return ans;
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

vector<point> CH_Andrew(vector<point> &Pts) {    // overall O(n log n)
    int n = Pts.size(), k = 0;
    vector<point> H(2 * n);
    sort(Pts.begin(), Pts.end());                  // sort the points by x/y
    for (int i = 0; i < n; ++i) {                  // build lower hull
        while ((k >= 2) && !ccw(H[k - 2], H[k - 1], Pts[i])) --k;
        H[k++] = Pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) {       // build upper hull
        while ((k >= t) && !ccw(H[k - 2], H[k - 1], Pts[i])) --k;
        H[k++] = Pts[i];
    }
    H.resize(k);
    return H;
}

struct tree {
    int x, y, v, l;
};

// code from book for convex hull

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cases = 1;
    while (cin >> N, N) {
        if (cases != 1) cout << endl;
        vector<tree> t(N);
        for (int i = 0; i < N; ++i) cin >> t[i].x >> t[i].y >> t[i].v >> t[i].l;
        int bestMask = -1, bestValue = 1e9; // bit is on if tree is still standing. value is of the trees chopped
        int bestTrees = -1; // number of trees chopped
        double bestRemaining = -1; // remaining perimeter after chopping
        for (int i = 0; i <= (1 << N) - 1; ++i) {
            // get perimeter of standing trees
            vector<point> Pts;
            for (int j = 0; j < N; ++j) {
                if (i & (1 << j)) {
                    Pts.emplace_back(t[j].x, t[j].y);
                }
            }
            auto CH = CH_Andrew(Pts);
            double perimeterCH = perimeter(CH);
            // get length of chopped trees
            int length = 0;
            for (int j = 0; j < N; ++j) {
                if (!(i & (1 << j))) {
                    length += t[j].l;
                }
            }
            if (length < perimeterCH) continue; // go to next test if not enough to build fence
            // get value of chopped trees
            int value = 0;
            for (int j = 0; j < N; ++j) {
                if (!(i & (1 << j))) {
                    value += t[j].v;
                }
            }
            if (value <= bestValue) {
                bestValue = value;
                bestMask = i;
                bestTrees = min(N - __builtin_popcount(i), bestTrees);
                bestRemaining = length - perimeterCH;
            }
        }
        cout << "Forest " << cases++ << endl;
        cout << "Cut these trees:";
        for (int i = 0; i < N; ++i) {
            if (!(bestMask & (1 << i))) {
                cout << " " << i + 1;
            }
        }
        cout << endl;
        cout << "Extra wood: " << fixed << setprecision(2) << bestRemaining << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
