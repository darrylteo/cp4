#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;

    bool operator<(const point &p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

point vec(point a, point b) {
    point p = {b.x - a.x, b.y - a.y};
    return p;
}

int cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

bool parallel(point a, point b) {
    return cross(a, b) == 0;
}

bool perpendicular(point a, point b) {
    return dot(a, b) == 0;
}

point points[4];
int lengths[4];

// sort points counterclockwise relative to points[0]
bool cmp(point a, point b) {
    point p = vec(points[0], a);
    point q = vec(points[0], b);
    return atan2(p.y, p.x) < atan2(q.y, q.x);
}

// ref: https://github.com/frcepeda/Contest-Archive/blob/master/UVa/11800%20-%20Determine%20the%20Shape.cpp
// good angle trick to arrange the points

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        for (int i = 0; i < 4; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        sort(points, points + 4);
        sort(points + 1, points + 4, cmp);

        for (int i = 0; i < 4; ++i) {
            lengths[i] = (points[i].x - points[(i + 1) % 4].x) * (points[i].x - points[(i + 1) % 4].x) +
                         (points[i].y - points[(i + 1) % 4].y) * (points[i].y - points[(i + 1) % 4].y);
        }

        // bottom right angle
        bool rightAngle = perpendicular(vec(points[0], points[1]), vec(points[1], points[2]));

        if (lengths[0] == lengths[1] && lengths[1] == lengths[2] && lengths[2] == lengths[3]) {
            if (rightAngle) {
                cout << "Case " << cases << ": Square\n";
            } else {
                cout << "Case " << cases << ": Rhombus\n";
            }
        } else if (lengths[0] == lengths[2] && lengths[1] == lengths[3]) {
            if (rightAngle) {
                cout << "Case " << cases << ": Rectangle\n";
            } else {
                cout << "Case " << cases << ": Parallelogram\n";
            }
        } else if (parallel(vec(points[0], points[1]), vec(points[2], points[3])) ||
                   parallel(vec(points[0], points[3]), vec(points[1], points[2]))) {
            cout << "Case " << cases << ": Trapezium\n";
        } else {
            cout << "Case " << cases << ": Ordinary Quadrilateral\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}