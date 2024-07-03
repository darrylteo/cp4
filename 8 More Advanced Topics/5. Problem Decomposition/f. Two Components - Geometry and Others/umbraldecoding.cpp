#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct umbra {
    ll x, y, b;
};

struct rect {
    ll x1, y1, x2, y2;
};

struct point {
    ll x, y;
};

inline bool inUm(umbra um, point pt) {
    return abs((um.x - pt.x) * (um.x - pt.x) * (um.x - pt.x)) +
           abs((um.y - pt.y) * (um.y - pt.y) * (um.y - pt.y)) <= um.b;
}

inline bool umInRect(umbra um, rect r) {
    return r.x1 <= um.x && um.x <= r.x2 && r.y1 <= um.y && um.y <= r.y2;
};

point closestPt(umbra um, rect r) {
    ll x = um.x, y = um.y;
    if (x < r.x1) x = r.x1;
    if (x > r.x2) x = r.x2;
    if (y < r.y1) y = r.y1;
    if (y > r.y2) y = r.y2;
    return {x, y};
}

void process(vector<rect> &dest, rect r, umbra um) {
    // rect in umbra, ignore
    vector<point> pts = {{r.x1, r.y1},
                         {r.x1, r.y2},
                         {r.x2, r.y1},
                         {r.x2, r.y2}};
    bool allIn = true;
    for (point pt: pts) {
        if (abs(pt.x - um.x) + abs(pt.y - um.y) > 1000 || !inUm(um, pt)) {
            allIn = false;
            break;
        }
    }
    if (allIn) return;

    // check if rect completely outside umbra. if yes, add to dest
    // if umbra in rect, this check does nothing
    if (!umInRect(um, r)) {
        point pt = closestPt(um, r);
        if (abs(pt.x - um.x) + abs(pt.y - um.y) > 1000 || !inUm(um, pt)) {
            dest.push_back(r);
            return;
        }
    }

    // do recursive cuts
    ll midx = (r.x1 + r.x2) / 2, midy = (r.y1 + r.y2) / 2;
    process(dest, {r.x1, r.y1, midx, midy}, um);
    if (midx + 1 <= r.x2) process(dest, {midx + 1, r.y1, r.x2, midy}, um);
    if (midy + 1 <= r.y2) process(dest, {r.x1, midy + 1, midx, r.y2}, um);
    if (midx + 1 <= r.x2 && midy + 1 <= r.y2) process(dest, {midx + 1, midy + 1, r.x2, r.y2}, um);
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_8_Advanced_Topics/8.7_Problem_Decomposition/kattis_umbraldecoding.cpp
// hard qn!

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    vector<rect> r1, r2; // alternate between these to cut rects for 1 umbra at a time
    cin >> n >> k;
    r1.emplace_back(rect{0, 0, n, n});
    for (int i = 0; i < k; ++i) {
        vector<rect> &source = i % 2 == 0 ? r1 : r2;
        vector<rect> &dest = i % 2 == 0 ? r2 : r1;

        int x, y, b;
        cin >> x >> y >> b;
        umbra umb = {x, y, b};

        dest.clear();
        for (rect rec: source) process(dest, rec, umb);
    }

    vector<rect> &final = k % 2 == 0 ? r1 : r2;
    ll ans = 0;
    for (rect rec: final) ans += (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1);
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
