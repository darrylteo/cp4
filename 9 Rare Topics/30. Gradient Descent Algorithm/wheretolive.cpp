#include <bits/stdc++.h>

using namespace std;

const int dirr[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dirc[] = {1, -1, 0, 0, 1, -1, -1, 1};

struct point {
    int x, y;
};

vector<point> points;

double getDist(int r, int c) {
    double total = 0;
    for (auto &p: points) {
        total += (p.x - r) * (p.x - r) + (p.y - c) * (p.y - c);
    }
    return total;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    while (cin >> N, N) {
        points.clear();
        for (int i = 0; i < N; i++) {
            point p;
            cin >> p.x >> p.y;
            points.push_back(p);
        }
        int r = 0, c = 0; // start
        double dist = getDist(r, c);
        while (true) {
            bool found = false;
            for (int i = 0; i < 8; i++) {
                int newr = r + dirr[i];
                int newc = c + dirc[i];
                if (newr >= 0 && newr <= 1000 && newc >= 0 && newc <= 1000) {
                    double newdist = getDist(newr, newc);
                    if (newdist < dist) {
                        dist = newdist;
                        r = newr;
                        c = newc;
                        found = true;
                    } else if (newdist == dist) {
                        if (newr < r || (newr == r && newc < c)) {
                            r = newr;
                            c = newc;
                            found = true;
                        }
                    }
                }
            }
            if (!found) {
                break;
            }
        }
        cout << r << " " << c << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
