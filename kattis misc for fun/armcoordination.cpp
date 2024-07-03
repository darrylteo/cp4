#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, r;
    cin >> x >> y >> r;
    cout << x - r << " " << y - r << endl;
    cout << x + r << " " << y - r << endl;
    cout << x + r << " " << y + r << endl;
    cout << x - r << " " << y + r << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
