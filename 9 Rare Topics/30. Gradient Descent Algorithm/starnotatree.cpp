#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};

struct point {
    ld x, y;
};

vector<point> points;

ld getDist(ld x, ld y) {
    ld dist = 0;
    for (auto & p : points) {
        dist += sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }
    return dist;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;
    points.resize(N);
    ld x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        ld a, b;
        cin >> a >> b;
        points[i] = {a, b};
        x += a;
        y += b;
    }
    x /= N;
    y /= N;
    ld dist = getDist(x, y); // start from here then local search
    for (ld d = 1000; d > 1e-12; d *= 0.99) {
        bool found = false;
        while (!found) {
            found = true;
            for (int i = 0; i < 4; i++) {
                ld nx = x + dirr[i] * d;
                ld ny = y + dirc[i] * d;
                ld ndist = getDist(nx, ny);
                if (ndist < dist) {
                    dist = ndist;
                    x = nx;
                    y = ny;
                    found = false;
                    break;
                }
            }
        }
    }
    cout << fixed << setprecision(10) << dist << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
