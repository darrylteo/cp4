#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M, N, ax, ay, bx, by;
    double R;
    cin >> M >> N >> R >> ax >> ay >> bx >> by;
    // rad + arc
    double ans = R/N * abs(ay - by); // radial distance
    double angle = abs(ax - bx) * M_PI / M;
    ans += R * angle * min(ay,by) / N; // arc distance
    // rad only
    double ans2 = R/N * abs(ay + by);
    // get best
    cout << fixed << setprecision(10) << min(ans, ans2) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}