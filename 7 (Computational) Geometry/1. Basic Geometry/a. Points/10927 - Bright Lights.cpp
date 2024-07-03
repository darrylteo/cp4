#include <bits/stdc++.h>

using namespace std;

// ref: https://blog.csdn.net/zxy_snow/article/details/6692840

struct point {
    long long x, y, h;
    double t;

    bool operator<(const point &p) const {
        if (t == p.t) return x*x + y*y < p.x*p.x + p.y*p.y; // closest first
        return t < p.t;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, cases = 1;
    while (cin >> n && n) {
        vector<point> p(n), bad;
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y >> p[i].h;
            p[i].t = atan2(p[i].y, p[i].x); // angle from 0 to 180
        }
        sort(p.begin(), p.end());
        long long h = p[0].h;
        for (int i = 1; i < n; i++) {
            if (p[i].t == p[i - 1].t) {
                if (p[i].h <= h) bad.push_back(p[i]);
                else h = p[i].h;
            } else {
                h = p[i].h;
            }
        }
        sort(bad.begin(), bad.end(), [](const point &a, const point &b) { // sort by x, y
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });
        cout << "Data set " << cases++ << ":\n";
        if (bad.empty()) cout << "All the lights are visible.\n";
        else {
            cout << "Some lights are not visible:\n";
            for (int i = 0; i < bad.size(); i++) {
                cout << "x = " << bad[i].x << ", y = " << bad[i].y;
                if (i < bad.size() - 1) cout << ";\n";
                else cout << ".\n";
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}