#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int t;
    cin >> t;
    while (t--) {
        int century, y, m, d;
        cin >> century >> y >> m >> d;
        int year = century * 100 + y;
        bool leap = false;
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                leap = year % 400 == 0;
            } else {
                leap = true;
            }
        }

        int daysInMonth[] = {31, 28 + leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // either use next permutation or manually permute y m d
        vector<tuple<int, int, int>> validDates;
        int y1 = y, m1 = m, d1 = d;
        if (m1 > 0 && d1 > 0 && m1 <= 12 && d1 <= daysInMonth[m1 - 1]) validDates.emplace_back(y1, m1, d1);
        y1 = y, m1 = d, d1 = m;
        if (m1 > 0 && d1 > 0 && m1 <= 12 && d1 <= daysInMonth[m1 - 1]) validDates.emplace_back(y1, m1, d1);
        y1 = m, m1 = y, d1 = d;
        if (m1 > 0 && d1 > 0 && m1 <= 12 && d1 <= daysInMonth[m1 - 1]) validDates.emplace_back(y1, m1, d1);
        y1 = m, m1 = d, d1 = y;
        if (m1 > 0 && d1 > 0 && m1 <= 12 && d1 <= daysInMonth[m1 - 1]) validDates.emplace_back(y1, m1, d1);
        y1 = d, m1 = y, d1 = m;
        if (m1 > 0 && d1 > 0 && m1 <= 12 && d1 <= daysInMonth[m1 - 1]) validDates.emplace_back(y1, m1, d1);
        y1 = d, m1 = m, d1 = y;
        if (m1 > 0 && d1 > 0 && m1 <= 12 && d1 <= daysInMonth[m1 - 1]) validDates.emplace_back(y1, m1, d1);

        sort(validDates.begin(), validDates.end());
        if (validDates.empty()) {
            cout << -1 << endl;
        } else {
            cout << setfill('0') << setw(2) << get<0>(validDates[0]) << " ";
            cout << setfill('0') << setw(2) << get<1>(validDates[0]) << " ";
            cout << setfill('0') << setw(2) << get<2>(validDates[0]) << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}