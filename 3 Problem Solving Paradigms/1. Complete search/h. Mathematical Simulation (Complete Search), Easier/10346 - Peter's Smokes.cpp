#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCigs, y;
    while (cin >> numCigs >> y) {
        int ans = 0, butts = 0;
        while (numCigs) {
            ans += numCigs;
            butts += numCigs;
            numCigs = butts / y; // new cigs rolled
            butts %= y; // leftover butts that don't make a new cig
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}