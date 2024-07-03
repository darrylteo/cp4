#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;

inline bool canCover(double length) {
    double covered = 0;
    int rem = n;
    for (int i: v) {
        if (covered - i < 1e-9) {
            covered = i + 2 * length;
            rem--;
            if (rem == -1) return false;
        }
    }
    return true;
}

// 2*length because u put it length away from curr house, and can cover another length away from it
// x1 --- WIFI HERE --- cover till here

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        v.resize(m);
        for (int &i: v) cin >> i;
        sort(v.begin(), v.end());
        double l = 0, r = 1e6;
        while (abs(r - l) > 1e-2) {
            double mid = (l + r) / 2;
            if (canCover(mid)) r = mid;
            else l = mid;
        }
        cout << fixed << setprecision(1) << r << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}