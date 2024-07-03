#include <bits/stdc++.h>

using namespace std;

const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dateToDays(const string &s, int cumDaysInMonth[]) {
    int day = 0, month = 0;
    month = stoi(s.substr(0, 2));
    day = stoi(s.substr(3, 2));
    return month==1 ? day - 1 : cumDaysInMonth[month - 2] + day - 1;
}

string daysToDate(int days, int cumDaysInMonth[]) {
    int month = 0, day = 0;
    for (int i = 0; i < 12; i++) {
        if (days < cumDaysInMonth[i]) {
            month = i + 1;
            day = days - (i == 0 ? 0 : cumDaysInMonth[i - 1]) + 1;
            break;
        }
    }
    string s = to_string(month);
    if (s.length() == 1) s = "0" + s;
    s += "-";
    string s2 = to_string(day);
    if (s2.length() == 1) s2 = "0" + s2;
    s += s2;
    return s;
}

// sort by gapFriend (desc), then gap27(asc). first element is biggest gap from friends, smallest gap from 27 oct
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<0>(a) > get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // brute force, check every possible day out of 365 [0,...,364] days and see which is furthest from each of his friends
    // check both forward ONLY (dont care if his friend bday tmrw) and take min. also check days after 27 oct
    int n;
    cin >> n;
    int days[n], cumDaysInMonth[12], gapFriend[365], gap27[365];
    fill(gapFriend, gapFriend + 365, 1000);
//    fill(gap27, gap27 + 365, 1000); // we will fill all of gap27 later
    for (int i = 0; i < 12; i++) cumDaysInMonth[i] = i == 0 ? daysInMonth[i] : cumDaysInMonth[i - 1] + daysInMonth[i];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> s;
        days[i] = dateToDays(s, cumDaysInMonth);
    }

    // update friend gaps
    for (int i = 0; i < 365; i++) {
        for (int j = 0; j < n; j++) {
            int daysSinceLastBday = i - days[j];
            if (daysSinceLastBday < 0) daysSinceLastBday += 365;
            gapFriend[i] = min(gapFriend[i], daysSinceLastBday);
        }
    }

    // update oct27 gaps
    int oct27 = dateToDays("10-27", cumDaysInMonth) + 1; // must be AFTER this date
    for (int i = 0; i < 365; i++) {
        int daysSince27 = i - oct27;
        if (daysSince27 < 0) daysSince27 += 365;
        gap27[i] = daysSince27;
    }

    vector<tuple<int, int, int>> gapFriendAndOct27;
    gapFriendAndOct27.reserve(365);
    for (int i = 0; i < 365; i++) gapFriendAndOct27.emplace_back(gapFriend[i], gap27[i], i);
    sort(gapFriendAndOct27.begin(), gapFriendAndOct27.end(), cmp);

    cout << daysToDate(get<2>(gapFriendAndOct27[0]), cumDaysInMonth) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}