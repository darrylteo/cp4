#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

double humidex(double t, double d) {
    double e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16))));
    double h = 0.5555 * (e - 10.0);
    return t + h;
}

double dewpoint(double t, double h) {
    return 1 / (1 / 273.16 - (log(((h - t) / 0.5555 + 10.0) / 6.11) / 5417.7530)) - 273.16;
}

double temperature(double d, double h) {
    double e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16))));
    double h1 = 0.5555 * (e - 10.0);
    return h - h1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double t, d, h;
    double d1, d2;
    string s1, s2;
    while (cin >> s1 >> d1 >> s2 >> d2) {
        if (s1 == "E") break;
        if (s1 == "T") t = d1;
        if (s1 == "D") d = d1;
        if (s1 == "H") h = d1;
        if (s2 == "T") t = d2;
        if (s2 == "D") d = d2;
        if (s2 == "H") h = d2;
        if (s1 == "T" && s2 == "D") {
            h = humidex(t, d);
            cout << "T " << fixed << setprecision(1) << t << " D " << fixed << setprecision(1) << d << " H " << fixed
                 << setprecision(1) << h << '\n';
        }
        if (s1 == "T" && s2 == "H") {
            d = dewpoint(t, h);
            cout << "T " << fixed << setprecision(1) << t << " D " << fixed << setprecision(1) << d << " H " << fixed
                 << setprecision(1) << h << '\n';
        }
        if (s1 == "D" && s2 == "T") {
            h = humidex(t, d);
            cout << "T " << fixed << setprecision(1) << t << " D " << fixed << setprecision(1) << d << " H " << fixed
                 << setprecision(1) << h << '\n';
        }
        if (s1 == "D" && s2 == "H") {
            t = temperature(d, h);
            cout << "T " << fixed << setprecision(1) << t << " D " << fixed << setprecision(1) << d << " H " << fixed
                 << setprecision(1) << h << '\n';
        }
        if (s1 == "H" && s2 == "T") {
            d = dewpoint(t, h);
            cout << "T " << fixed << setprecision(1) << t << " D " << fixed << setprecision(1) << d << " H " << fixed
                 << setprecision(1) << h << '\n';
        }
        if (s1 == "H" && s2 == "D") {
            t = temperature(d, h);
            cout << "T " << fixed << setprecision(1) << t << " D " << fixed << setprecision(1) << d << " H " << fixed
                 << setprecision(1) << h << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

