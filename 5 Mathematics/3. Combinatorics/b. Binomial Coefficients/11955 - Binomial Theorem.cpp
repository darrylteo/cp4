#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull nCk(ull n, ull k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    ull result = n;
    for (ull i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        string s, x, y, powerStr;
        cin >> s;
        int i = 1;
        while (s[i] != '+') {
            x += s[i];
            i++;
        }
        i++;
        while (s[i] != ')') {
            y += s[i];
            i++;
        }
        i += 2;
        while (i < s.size()) {
            powerStr += s[i];
            i++;
        }
        int power = stoi(powerStr);
        cout << "Case " << cases << ": ";
        if (power == 0) {
            cout << 1 << '\n';
            continue;
        }
        if (power == 1) {
            cout << x << "+" << y << '\n';
            continue;
        }
        cout << x << "^" << power;
        for (int j = 1; j < power; ++j) {
            cout << "+" << nCk(power, j) << "*";
            if (power - j > 1) {
                cout << x << "^" << power - j << "*";
            } else {
                cout << x << "*";
            }
            if (j > 1) {
                cout << y << "^" << j;
            } else {
                cout << y;
            }
        }
        cout << "+" << y << "^" << power << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


