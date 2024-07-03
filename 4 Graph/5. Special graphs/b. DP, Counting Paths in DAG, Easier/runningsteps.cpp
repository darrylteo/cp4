#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// DBL_MAX = 1.79769e+308 but loss of precision !!!! grrr
ull NCR(int n, int r) {
    if (r == 0) return 1;
    if (r > n / 2) return NCR(n, n - r);
    ull res = 1;
    for (int k = 1; k <= r; ++k) {
        res *= n - k + 1;
        res /= k;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull ans[101] = {};
    for (int i = 2; i < 101; i += 2) {
        // divide by 2 gives number of 2s. divide again since we only consider all left leg steps. we square to find right leg steps
        int cntTwosLeft = i / 4;
        // if we have odd number of 2step on left leg (e.g. on 6), 1 will be converted to left 1step and right 1step but we only consider left leg here
        int cntOnesLeft = i % 4 != 0;
        while (cntTwosLeft >= cntOnesLeft) {
            ans[i] += NCR(cntTwosLeft + cntOnesLeft, cntOnesLeft) * NCR(cntTwosLeft + cntOnesLeft, cntOnesLeft);
            cntTwosLeft--; // convert a 2step on left leg to 2 1steps on left leg
            cntOnesLeft += 2;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int caseNum, n;
        cin >> caseNum >> n;
        cout << caseNum << ' ' << fixed << setprecision(0) << ans[n] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
