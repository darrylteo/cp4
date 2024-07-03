#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int G, T, N, sum = 0;
    cin >> G >> T >> N;
    sum = 0.9 * (G - T);
    while (N--) {
        int x;
        cin >> x;
        sum -= x;
    }
    cout << sum << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




