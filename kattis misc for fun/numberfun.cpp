#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        double a, b, c;
        cin >> a >> b >> c;
        if (a + b == c || a - b == c || b - a == c || a * b == c || a / b == c || b / a == c) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}