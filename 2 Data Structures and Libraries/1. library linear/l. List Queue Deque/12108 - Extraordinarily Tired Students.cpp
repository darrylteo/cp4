#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    int n;
    int caseNo = 0;
    while (cin >> n, n) {
        cout << "Case " << ++caseNo << ": ";
        int LCM = 1; // can find 1 complete cycle across all students LCM or just multiply all also ok
        vector<int> a(n), b(n), c(n), d(n); // d is total time for 1 cycle
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            d[i] = a[i] + b[i];
            LCM = LCM * d[i] / __gcd(LCM, d[i]);
        }
        int ans = -1;
        for (int t = 1; t <= LCM * 2; ++t) { // if not all awake by now, it would have cycled back to original state
            // check how many sleeping
            int noSleeping = 0;
            bool moreSleeping = false;
            for (int i = 0; i < n; ++i) {
                if (c[i] > a[i]) {
                    noSleeping++;
                }
            }
            // check if can break
            if (noSleeping == 0) {
                ans = t;
                break;
            }
            if (noSleeping > n - noSleeping) {
                moreSleeping = true;
            }
            // update c (sleep cycle)
            for (int i = 0; i < n; ++i) {
                if (c[i] == d[i]) {
                    c[i] = 1; // reset
                } else {
                    c[i]++;
                }
            }

            // if planning to sleep, check whether more sleeping or not (based on his last awake time)
            for (int i = 0; i < n; ++i) {
                if (c[i] == a[i] + 1) {
                    if (!moreSleeping) {
                        c[i] = 1; // reset
                    }
                }
            }
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
