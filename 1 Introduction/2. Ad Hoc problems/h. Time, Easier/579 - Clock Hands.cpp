#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int H, M;
    while (scanf("%d:%d", &H, &M) == 2) {
        if (H == 0 && M == 0) break;
        // 60 minutes = 30 degrees on hour hand
        // 1 minute = 0.5 degrees on hour hand
        // 1 minute = 6 degrees on minute hand
        // 1 hour = 30 degrees on minute hand
        // minute hand = 6 * M
        // hour hand = 30 * H + 0.5 * M
        // difference = abs(hour hand - minute hand)
        double angle = abs(30.0 * H - 5.5 * M);
        if (angle > 180) angle = 360 - angle;
        printf("%.3lf\n", angle);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}