#include <bits/stdc++.h>

using namespace std;

int main() {
    int low = 1, high, w1, w2, n;
    cin >> n;
    high = n;
    while (true) {
        int m1 = low + (int)(high - low + 1) * 0.25, m2 = low + (int)(high - low + 1) * 0.5-1, m3 = low + (int)(high - low + 1) * 0.75-1;
        cout << "Q " << low << ' ' << m2 << ' ' << m1 << ' ' << m3 << endl;
        cout.flush();
        cin >> w1 >> w2;

        if (w1 == 0 && w2 == 0) {
            if (high - m3 <= 1) {
                cout << "A " << high << endl;
                return 0;
            }
            low = m3;
            high = min(high + 1, n);
        } else if (w1 == 0 && w2 == 1) {
            if (m3  - m2  <= 1) {
                cout << "A " << m3 << endl;
                return 0;
            }
            low = m2;
            high = m3 + 1;
        } else if (w1 == 1 && w2 == 1) {
            if (m2 == m1) {
                cout << "A " << m1 << endl;
                return 0;
            }
            low = m1 - 1;
            high = m2 + 1;
        } else if (w1 == 1 && w2 == 0) {
            if (m1 - low <= 1) {
                cout << "A " << low << endl;
                return 0;
            }
            low = max(low - 1, 1);
            high = m1;
        }
    }
}