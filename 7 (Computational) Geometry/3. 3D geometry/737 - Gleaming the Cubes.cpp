#include <bits/stdc++.h>

using namespace std;

// qn look hard at first but notice that they just want intersection of ALL cubes, not all pair of cubes

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        int lx = INT_MIN, ly = INT_MIN, lz = INT_MIN, rx = INT_MAX, ry = INT_MAX, rz = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int x, y, z, r;
            cin >> x >> y >> z >> r;
            lx = max(lx, x);
            ly = max(ly, y);
            lz = max(lz, z);
            rx = min(rx, x + r);
            ry = min(ry, y + r);
            rz = min(rz, z + r);
        }
        cout << max(0, rx - lx) * max(0, ry - ly) * max(0, rz - lz) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
