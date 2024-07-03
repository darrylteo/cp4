#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    double C, w, l, total = 0;
    int L;
    cin >> C >> L;
    while (L--) {
        cin >> w >> l;
        total += w * l * C;
    }
    cout << fixed << setprecision(7) << total << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
