#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// no need Linear Diophantine Equation -_-
// N = 10a + b, M = a
// N - M = 9a + b
// a = (N - M - b) / 9 for all b in [0, 9]

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll C;
    while (cin >> C, C) {
        int flag = 0;
        for (ll b = 9; b >= 0; --b) {
            if ((C - b) % 9 == 0) {
                ll a = (C - b) / 9;
                if (flag) cout << " ";
                cout << 10 * a + b;
                flag = 1;
            }
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


