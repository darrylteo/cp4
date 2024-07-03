#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double d = M_PI * 60 / 28;
    int T;
    cin >> T;
    while (T--) {
        string line;
        getline(cin >> ws, line);
        double ans = line.size(); // starting soln
        for (int i = 0; i < line.size() - 1; ++i) {
            int a, b;
            if (line[i] == ' ') a = 26;
            else if (line[i] == '\'') a = 27;
            else a = line[i] - 'A';
            if (line[i + 1] == ' ') b = 26;
            else if (line[i + 1] == '\'') b = 27;
            else b = line[i + 1] - 'A';
            ans += min(abs(a - b), 28 - abs(a - b)) * d / 15;
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
