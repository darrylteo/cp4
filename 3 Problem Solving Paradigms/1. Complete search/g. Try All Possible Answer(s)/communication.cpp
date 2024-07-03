#include <bits/stdc++.h>

using namespace std;

// after some testing, it seems to be a fixed size of 8 bits
// we remove the first 1 bit if it exceeds 8 bits

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 0; i < 256; ++i) {
            int ans = i ^ (i << 1);
            if (ans > 255) ans -= 256;
            if (ans == x) {
                cout << i << ' ';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}