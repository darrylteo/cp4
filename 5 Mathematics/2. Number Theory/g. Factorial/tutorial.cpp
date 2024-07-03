#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull m, n, t;
    cin >> m >> n >> t;
    if (t == 1) {
        ull curr = 1;
        for (ull i = 2; i <= n; ++i) {
            curr *= i;
            if (curr > m) {
                cout << "TLE";
                return 0;
            }
        }
    } else if (t == 2) {
        ull curr = 1;
        for (ull i = 0; i < n; ++i) {
            curr *= 2;
            if (curr > m) {
                cout << "TLE";
                return 0;
            }
        }
    } else if (t == 3) {
        if (pow(n, 4) > m) {
            cout << "TLE";
            return 0;
        }
    } else if (t == 4) {
        if (pow(n, 3) > m) {
            cout << "TLE";
            return 0;
        }
    } else if (t == 5) {
        if (pow(n, 2) > m) {
            cout << "TLE";
            return 0;
        }
    } else if (t == 6) {
        if (n * log2(n) > m) {
            cout << "TLE";
            return 0;
        }
    } else if (t == 7) {
        if (n > m) {
            cout << "TLE";
            return 0;
        }
    }
    cout << "AC";


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}