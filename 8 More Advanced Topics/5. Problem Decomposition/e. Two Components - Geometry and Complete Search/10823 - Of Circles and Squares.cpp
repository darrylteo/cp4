#include <bits/stdc++.h>

using namespace std;

struct circle {
    int x{}, y{}, r{};
    int R{}, G{}, B{};
};

struct square {
    int x{}, y{}, s{};
    int R{}, G{}, B{};
};

int inCircle(circle &c, int x, int y) {
    int ans = (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) - c.r * c.r;
    if (ans < 0) return 1;
    if (ans == 0) return 0;
    return -1;
}

int inSquare(square &sq, int x, int y) {
    if (x > sq.x && x < sq.x + sq.s && y > sq.y && y < sq.y + sq.s) return 1;
    if (x < sq.x || x > sq.x + sq.s || y < sq.y || y > sq.y + sq.s) return -1;
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        if (cases > 1) cout << '\n';
        cout << "Case " << cases << ":\n";
        int N, Q;
        cin >> N >> Q;
        vector<circle> circles;
        vector<square> squares;
        while (N--) {
            string s;
            cin >> s;
            if (s == "CIRCLE") {
                circle c;
                cin >> c.x >> c.y >> c.r >> c.R >> c.G >> c.B;
                circles.push_back(c);
            } else {
                square sq;
                cin >> sq.x >> sq.y >> sq.s >> sq.R >> sq.G >> sq.B;
                squares.push_back(sq);
            }
        }
        while (Q--) {
            int sumR = 0, sumG = 0, sumB = 0, cntIn = 0, isBlack = 0;
            int x, y;
            cin >> x >> y;
            for (auto &c: circles) {
                int in = inCircle(c, x, y);
                if (in == 1) {
                    sumR += c.R;
                    sumG += c.G;
                    sumB += c.B;
                    cntIn++;
                } else if (in == 0) {
                    isBlack = 1;
                    break;
                }
            }
            if (isBlack) {
                cout << "(0, 0, 0)\n";
                continue;
            }
            for (auto &sq: squares) {
                int in = inSquare(sq, x, y);
                if (in == 1) {
                    sumR += sq.R;
                    sumG += sq.G;
                    sumB += sq.B;
                    cntIn++;
                } else if (in == 0) {
                    isBlack = 1;
                    break;
                }
            }
            if (isBlack) {
                cout << "(0, 0, 0)\n";
                continue;
            }
            if (cntIn == 0) {
                cout << "(255, 255, 255)\n";
                continue;
            }
            cout << "(" << round((double) sumR / cntIn) << ", " << round((double) sumG / cntIn) << ", "
                 << round((double) sumB / cntIn) << ")\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
