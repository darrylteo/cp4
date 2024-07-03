#include <bits/stdc++.h>

using namespace std;

// dT/dR = 0 implies R = b / 2a

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int numGear;
        cin >> numGear;
        int bestGear;
        double bestTorque = 0;
        for (int gear = 1; gear <= numGear; ++gear) {
            int a, b, c;
            cin >> a >> b >> c;
            double R = b / (2.0 * a);
            double torque = -a * R * R + b * R + c;
            if (torque > bestTorque) {
                bestTorque = torque;
                bestGear = gear;
            }
        }
        cout << bestGear << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}