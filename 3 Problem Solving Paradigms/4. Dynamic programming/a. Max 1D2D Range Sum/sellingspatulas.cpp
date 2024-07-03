#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<double> v(1500, -0.08);
        for (int i = 0; i < n; ++i) {
            int time;
            double px;
            cin >> time >> px;
            v[time] += px;
        }
        double bestSum = 0, currSum = 0;
        int bestStart = 0, bestEnd = 0, currStart = 0;
        for (int i = 0; i < 1500; ++i) {
            currSum += v[i];
            if (currSum < EPS) { // SAD. if u don't put eps u will get wrong!! highly unsuspecting error
                currSum = 0;
                currStart = i + 1;
            }
            if (currSum > bestSum) {
                bestSum = currSum;
                bestStart = currStart;
                bestEnd = i;
            } else if (currSum == bestSum && (i - currStart) < (bestEnd - bestStart)) {
                bestStart = currStart;
                bestEnd = i;
            }
        }
        if (bestSum > 0) cout << fixed << setprecision(2) << bestSum << " " << bestStart << " " << bestEnd << "\n";
        else cout << "no profit\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
