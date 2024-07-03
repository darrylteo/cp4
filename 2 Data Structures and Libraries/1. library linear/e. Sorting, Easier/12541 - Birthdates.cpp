#include <bits/stdc++.h>

using namespace std;

struct person {
    string name;
    int d, m, y;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    vector<person> v(n);
    for (int i = 0; i < n; ++i) {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        v[i] = {name, d, m, y};
    }
    sort(v.begin(), v.end(), [](person a, person b) {
        if (a.y != b.y) return a.y < b.y;
        if (a.m != b.m) return a.m < b.m;
        return a.d < b.d;
    });
    cout << v[n - 1].name << endl;
    cout << v[0].name << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
