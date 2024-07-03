#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        double x, y;
        cin >> x >> y;
        int Q;
        cin >> Q;
        int found = 0;
        while (Q--) {
            double a, b;
            cin >> a >> b;
            if (found) continue;
            if ((x-a)*(x-a) + (y-b)*(y-b) <= 64) {
                found = 1;
            }
        }
        cout << (found ? "light a candle\n" : "curse the darkness\n");
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}