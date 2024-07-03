#include <bits/stdc++.h>

using namespace std;

// only qn in topic that must use n^2 LIS
// quite a pure dp question

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;
        vector<int> heights(n), widths(n), sumInc(n), sumDec(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> widths[i];
            sumInc[i] = sumDec[i] = widths[i]; // building by itself
        }
        for (int i = 0; i < n; ++i) { // curr building that we want to put in front of building j
            for (int j = i + 1; j < n; ++j) {
                // see if can put in front of j AND if it's better than the current set of building stack there (or itself)
                if (heights[i] < heights[j] && sumInc[i] + widths[j] > sumInc[j]) {
                    sumInc[j] = sumInc[i] + widths[j];
                }
                if (heights[i] > heights[j] && sumDec[i] + widths[j] > sumDec[j]) {
                    sumDec[j] = sumDec[i] + widths[j];
                }
            }
        }
        // find the best stack of buildings
        int incr = *max_element(sumInc.begin(), sumInc.end());
        int decr = *max_element(sumDec.begin(), sumDec.end());
        if (incr >= decr) {
            cout << "Case " << cases << ". Increasing (" << incr << "). Decreasing (" << decr << ")." << endl;
        } else {
            cout << "Case " << cases << ". Decreasing (" << decr << "). Increasing (" << incr << ")." << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
