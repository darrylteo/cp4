#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, k;
    cin >> n >> p >> k;
    int timeNow = 0;
    double totalTime = 0, spdUp = p / 100.0, currSpd = 1;
    while (n--) {
        int x;
        cin >> x;
        totalTime += (x - timeNow) * currSpd;
        currSpd += spdUp;
        timeNow = x;
    }
    totalTime += (k - timeNow) * currSpd; // last segment

    cout << fixed << setprecision(6) << totalTime << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}