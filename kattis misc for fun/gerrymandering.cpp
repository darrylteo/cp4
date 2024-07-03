#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> districts(m);
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        districts[a - 1].first += b;
        districts[a - 1].second += c;
    }
    int V = 0, wa = 0, wb = 0;
    for (int i = 0; i < m; ++i) {
        int a = districts[i].first;
        int b = districts[i].second;
        int total = a + b;
        V += total;
        if (a > b) {
            int wwa = a - (total / 2 + 1);
            int wwb = b;
            wa += wwa;
            wb += wwb;
            cout << "A " << wwa << " " << wwb << endl;
        } else {
            int wwa = a;
            int wwb = b - (total / 2 + 1);
            wa += wwa;
            wb += wwb;
            cout << "B " << wwa << " " << wwb << endl;
        }
    }
    cout << fixed << setprecision(10) << (double) abs(wa - wb) / V << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
