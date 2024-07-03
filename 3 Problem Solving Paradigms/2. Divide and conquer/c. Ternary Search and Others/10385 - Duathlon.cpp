#include <bits/stdc++.h>

using namespace std;

double getTime(double rDist, double rSpeed, double kDist, double kSpeed) {
    double time = 0;
    time += rDist / rSpeed;
    time += kDist / kSpeed;
    return time;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    while (cin >> t >> n) {
        vector<double> rSpeeds(n), kSpeeds(n);
        for (int i = 0; i < n; ++i) {
            cin >> rSpeeds[i] >> kSpeeds[i];
        }
        double lo = 0, hi = t; // we'll decide his running dist
        double bestOthers1, bestOthers2, cheatTime1, cheatTime2;
        for (int i = 0; i < 50; ++i) { // similar as BSTA
            double delta = (hi - lo) / 3.0; // 1/3rd of the range
            double m1 = lo + delta; // 1/3rd away from lo
            double m2 = hi - delta; // 1/3rd away from hi
            bestOthers1 = INT_MAX, bestOthers2 = INT_MAX;
            cheatTime1 = getTime(m1, rSpeeds.back(), t - m1, kSpeeds.back());
            cheatTime2 = getTime(m2, rSpeeds.back(), t - m2, kSpeeds.back());
            for (int j = 0; j < n - 1; ++j) {
                bestOthers1 = min(bestOthers1, getTime(m1, rSpeeds[j], t - m1, kSpeeds[j]));
                bestOthers2 = min(bestOthers2, getTime(m2, rSpeeds[j], t - m2, kSpeeds[j]));
            }
            // f(m1) f(m2) notation
            // i'm not able to see how this is a unimodel function but i just applied ternary search
            // clearly there will be a local min/max since it is not a monotone function but why is local min = global min?
            double fm1 = cheatTime1 - bestOthers1, fm2 = cheatTime2 - bestOthers2;
            if (fm1 < fm2) {
                hi = m2;
            } else {
                lo = m1;
            }
        }
        // for corner case so he must lose at least by 0.01 seconds (abs is for this too)
        if (cheatTime1 > bestOthers1 + 0.01) {
            cout << "The cheater cannot win." << endl;
        } else {
            cout << "The cheater can win by " << fixed << setprecision(0) << round(abs(bestOthers1 - cheatTime1) * 3600)
                 << " seconds with r = "
                 << fixed << setprecision(2) << round(lo * 100) / 100 << "km and k = "
                 << round((t - lo) * 100) / 100 << "km." << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
