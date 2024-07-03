#include <bits/stdc++.h>

using namespace std;

// weird qn... they never really specify but its just that beats can be off by 1 count

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        double b, p;
        cin >> b >> p;
        cout << fixed << setprecision(5) << 60 * (b - 1) / p << " " << 60 * b / p << " " << 60 * (b + 1) / p << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
