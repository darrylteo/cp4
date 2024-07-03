#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n >= 0) {
        int ans = -1;
        // just check till 20 since uDebug sample all people < 10
        // unsure of exact upper bound
        for (int i = 20; i >= 2; i--) {
            long long x = n;
            bool possible = true;
            for (int j = 0; j < i; j++) {
                // cannot give monke 1 coconut
                if (x % i != 1) {
                    possible = false;
                    break;
                }
                // (x - 1) / i will be integer if reach here
                x = (x - 1) * (i - 1) / i;
            }
            if (possible && x % i == 0) {
                ans = i;
                break;
            }
        }
        if (ans == -1) {
            cout << n << " coconuts, no solution\n";
        } else {
            cout << n << " coconuts, " << ans << " people and 1 monkey\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}