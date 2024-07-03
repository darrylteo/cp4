#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, ans = 0;
    cin >> x >> y;
    for (int i = 0; i < y; i++) {
        string s;
        cin >> s;
        for (char c: s) {
            if ( c == '.') {
                ans++;
            }
        }
    }

    cout << (double) ans / x / y<< endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
