#include <bits/stdc++.h>

using namespace std;

bool checkDate (int y, int m, int d) {
    int year = 2000 + y;
    if (year > 999) year -= 2000; // in case alr give 4 digit year
    bool leap = false;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            leap = year % 400 == 0;
        } else {
            leap = true;
        }
    }
    int daysInMonth[] = {31, 28 + leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m > 0 && d > 0 && m <= 12 && d <= daysInMonth[m - 1]) return true;
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int y, m, d;
    string s;
    cin >> s;
    sscanf(s.c_str(),"%d/%d/%d", &y, &m, &d);
    vector<tuple<int, int, int>> validDates;
    int y1 = y, m1 = m, d1 = d;
    if (checkDate(y1, m1, d1)) validDates.emplace_back(y1, m1, d1);
    y1 = y, m1 = d, d1 = m;
    if (checkDate(y1, m1, d1)) validDates.emplace_back(y1, m1, d1);
    y1 = m, m1 = y, d1 = d;
    if (checkDate(y1, m1, d1)) validDates.emplace_back(y1, m1, d1);
    y1 = m, m1 = d, d1 = y;
    if (checkDate(y1, m1, d1)) validDates.emplace_back(y1, m1, d1);
    y1 = d, m1 = y, d1 = m;
    if (checkDate(y1, m1, d1)) validDates.emplace_back(y1, m1, d1);
    y1 = d, m1 = m, d1 = y;
    if (checkDate(y1, m1, d1)) validDates.emplace_back(y1, m1, d1);

    sort(validDates.begin(), validDates.end());
    if (validDates.empty()) {
        cout << s << " is illegal" << endl;
    } else {
        if (get<0>(validDates[0]) > 999) cout << get<0>(validDates[0]) << "-"; // in case alr give 4 digit year
        else cout << get<0>(validDates[0]) + 2000 << "-";
        cout << setfill('0') << setw(2) << get<1>(validDates[0]) << "-";
        cout << setfill('0') << setw(2) << get<2>(validDates[0]) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}