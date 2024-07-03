#include <bits/stdc++.h>

using namespace std;

// algebra not bisection. speed = dist / time

struct shield {
    int lower, upper;
    double factor;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    vector<shield> shields(n);
    for (int i = 0; i < n; ++i) {
        cin >> shields[i].lower >> shields[i].upper >> shields[i].factor;
    }
    sort(shields.begin(), shields.end(), [](shield a, shield b) {
        return a.lower < b.lower;
    });
    double realFactor = 0; // real factor
    int currHeight = 0;
    for (shield s: shields) {
        int timeToShield = s.lower - currHeight; // time to reach shield (ySpeed is fixed at 1)
        realFactor += timeToShield;
        int timeInShield = s.upper - s.lower; // time in shield
        realFactor += timeInShield * s.factor;
        currHeight = s.upper;
    }
    int timeLast = y - currHeight;
    realFactor += timeLast;
    cout << fixed << setprecision(12) << x / realFactor << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
