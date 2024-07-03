#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int b, k, g;
    cin >> b >> k >> g;
    b--; // don't count initial bridge
    if (b % (k/g) == 0) {
        cout << b / (k/g) << endl;
    } else {
        cout << b / (k/g) + 1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}