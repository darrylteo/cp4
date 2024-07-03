#include <bits/stdc++.h>

using namespace std;

struct driver {
    string name, namelower;
    int min, sec, ms;

    bool operator<(const driver &d) const {
        if (min != d.min) return min < d.min;
        if (sec != d.sec) return sec < d.sec;
        if (ms != d.ms) return ms < d.ms;
        return namelower < d.namelower;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<driver> drivers(n);
        for (int i = 0; i < n; i++) {
            cin >> drivers[i].name;
            for (char c: drivers[i].name) {
                char tmp;
                tmp = (char) tolower(c);
                drivers[i].namelower += tmp;
            }
            string s;
            cin >> s >> drivers[i].min >> s >> drivers[i].sec >> s >> drivers[i].ms >> s;
        }
        sort(drivers.begin(), drivers.end());
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << "Row " << i / 2 + 1 << '\n';
            }
            cout << drivers[i].name << '\n';
        }
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

