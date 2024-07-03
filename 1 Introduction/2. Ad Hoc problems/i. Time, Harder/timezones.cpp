#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    map<string, double> timeZones;
    timeZones["UTC"] = 0;
    timeZones["GMT"] = 0;
    timeZones["BST"] = 1;
    timeZones["IST"] = 1;
    timeZones["WET"] = 0;
    timeZones["WEST"] = 1;
    timeZones["CET"] = 1;
    timeZones["CEST"] = 2;
    timeZones["EET"] = 2;
    timeZones["EEST"] = 3;
    timeZones["MSK"] = 3;
    timeZones["MSD"] = 4;
    timeZones["AST"] = -4;
    timeZones["ADT"] = -3;
    timeZones["NST"] = -3.5;
    timeZones["NDT"] = -2.5;
    timeZones["EST"] = -5;
    timeZones["EDT"] = -4;
    timeZones["CST"] = -6;
    timeZones["CDT"] = -5;
    timeZones["MST"] = -7;
    timeZones["MDT"] = -6;
    timeZones["PST"] = -8;
    timeZones["PDT"] = -7;
    timeZones["HST"] = -10;
    timeZones["AKST"] = -9;
    timeZones["AKDT"] = -8;
    timeZones["AEST"] = 10;
    timeZones["AEDT"] = 11;
    timeZones["ACST"] = 9.5;
    timeZones["ACDT"] = 10.5;
    timeZones["AWST"] = 8;

    int t;
    cin >> t;
    while (t--) {
        string a, b, c, d;
        int h = 0, m = 0;
        cin >> a >> b >> c;
        if (islower(b[0])) { // means normal time
            cin >> d;
            sscanf(a.c_str(), "%d:%d", &h, &m);
            if (b[0] == 'p' && h != 12) h += 12;
            if (b[0] == 'a' && h == 12) h = 0;
        } else { // midnight or noon
            d = c;
            c = b;
            if (a[0] == 'n') h = 12;
        }

        double timeDiff = timeZones[c] - timeZones[d]; // subtract this
        // add mins (or subtract)
        if (timeDiff - floor(timeDiff) > 1e-5) {
            if (timeDiff < 0){
                m += 30;
                if (m >= 60) {
                    m -= 60;
                    h++;
                }
            } else {
                m -= 30;
                if (m < 0) {
                    m += 60;
                    h--;
                }
            }
        }
        // add hours
        h -= (int) timeDiff;
        if (h < 0) h += 24;
        else if (h >= 24) h -= 24;

        // print
        if (m == 0 && h == 0) cout << "midnight" << endl;
        else if (m == 0 && h == 12) cout << "noon" << endl;
        else {
            if (h >= 12) {
                h -= 12;
                if (h == 0) h = 12;
                cout << h << ":" << setfill('0') << setw(2) << m << " p.m." << endl;
            } else {
                if (h == 0) h = 12;
                cout << h << ":" << setfill('0') << setw(2) << m << " a.m." << endl;
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}