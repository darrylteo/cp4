#include <bits/stdc++.h>

using namespace std;

// need formula.. ref: https://morris821028.github.io/2014/06/24/oj/uva/uva-427/
double eps = 1e-6;

// finding the worst case h (see diagram in link)
double ternary_search(double H, double W, double X, double Y) {
    double l = 0, r = M_PI / 2, m1, m2;
    double s1, h1, s2, h2;
    while (fabs(r - l) > eps) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        s1 = H * cos(m1) + W * sin(m1) - X;
        h1 = s1 * tan(m1) + W * cos(m1);
        s2 = H * cos(m2) + W * sin(m2) - X;
        h2 = s2 * tan(m2) + W * cos(m2);
        if (h1 < h2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return h1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    while (getline(cin, buf)) {
        stringstream ss(buf);
        string token;
        ss >> token;
        stringstream sst(token);
        double H, W, X, Y;
        getline(sst, token, ',');
        H = stod(token);
        getline(sst, token, ',');
        W = stod(token);
        if (H < W) swap(H, W);
        while (ss >> token) {
            stringstream sst(token);
            getline(sst, token, ',');
            X = stod(token);
            getline(sst, token, ',');
            Y = stod(token);
            double h = ternary_search(H, W, X, Y);
            if (h <= Y) cout << 'Y';
            else cout << 'N';
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}