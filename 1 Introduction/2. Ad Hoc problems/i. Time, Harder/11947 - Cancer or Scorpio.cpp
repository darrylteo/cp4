#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int d, m, y;
        m = stoi(s.substr(0, 2));
        d = stoi(s.substr(2, 2));
        y = stoi(s.substr(4, 4));
        tm t = {0, 0, 0, d + 40 * 7, m - 1, y - 1900}; // add 40 weeks
        mktime(&t);

        string zodiac;
        if (t.tm_mon == 0) {
            if (t.tm_mday < 21) zodiac = "capricorn";
            else zodiac = "aquarius";
        } else if (t.tm_mon == 1) {
            if (t.tm_mday < 20) zodiac = "aquarius";
            else zodiac = "pisces";
        } else if (t.tm_mon == 2) {
            if (t.tm_mday < 21) zodiac = "pisces";
            else zodiac = "aries";
        } else if (t.tm_mon == 3) {
            if (t.tm_mday < 21) zodiac = "aries";
            else zodiac = "taurus";
        } else if (t.tm_mon == 4) {
            if (t.tm_mday < 22) zodiac = "taurus";
            else zodiac = "gemini";
        } else if (t.tm_mon == 5) {
            if (t.tm_mday < 22) zodiac = "gemini";
            else zodiac = "cancer";
        } else if (t.tm_mon == 6) {
            if (t.tm_mday < 23) zodiac = "cancer";
            else zodiac = "leo";
        } else if (t.tm_mon == 7) {
            if (t.tm_mday < 22) zodiac = "leo";
            else zodiac = "virgo";
        } else if (t.tm_mon == 8) {
            if (t.tm_mday < 24) zodiac = "virgo";
            else zodiac = "libra";
        } else if (t.tm_mon == 9) {
            if (t.tm_mday < 24) zodiac = "libra";
            else zodiac = "scorpio";
        } else if (t.tm_mon == 10) {
            if (t.tm_mday < 23) zodiac = "scorpio";
            else zodiac = "sagittarius";
        } else if (t.tm_mon == 11) {
            if (t.tm_mday < 23) zodiac = "sagittarius";
            else zodiac = "capricorn";
        }

        cout << i + 1 << " " << setfill('0') << setw(2) << t.tm_mon + 1 << "/" << setfill('0') << setw(2) << t.tm_mday << "/" << t.tm_year + 1900 << " " << zodiac << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}