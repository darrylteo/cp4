#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        int l = 1, r = 1e9;
        string s1, s2;
        int x, fac = 1;
        for (int i = 0; i < n; i++) {
            cin >> s1 >> s2 >> x;
            if (s1[0] == 'l') {
                r = min(r, x - 1);
            } else if (s1[0] == 'g') {
                l = max(l, x + 1);
            } else {
                fac = lcm(fac, x);
            }
        }
        if (l > r) {
            cout << "none\n";
        } else if (r == 1e9) {
            cout << "infinite\n";
        } else {
            int found = 0;
            while (l % fac) ++l;
            for (int i = l; i <= r; i += fac) {
                cout << i << ' ';
                found = 1;
            }
            if (!found) cout << "none";
            cout << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


