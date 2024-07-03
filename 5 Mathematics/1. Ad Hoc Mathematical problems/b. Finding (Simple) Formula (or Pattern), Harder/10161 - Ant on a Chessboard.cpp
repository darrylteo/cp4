#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// count no. of steps since last sqaure number

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    while (cin >> n, n) {
        ll red = (ll) sqrt(n);
        ll steps = n - red * red;

        // sqaure numbers
        if (steps == 0) {
            if (red % 2 == 0)cout << red << " " << 1 << '\n';
            else cout << 1 << " " << red << '\n';
            continue;
        }

        // non sqaure numbers
        if (red % 2 == 0) {
            ll stepsUp = min(steps, red + 1);
            ll stepsLeft = max(0LL, steps - red - 1);
            cout << red + 1 - stepsLeft << " " << stepsUp << '\n';
        } else {
            ll stepsRight = min(steps, red + 1);
            ll stepsDown = max(0LL, steps - red - 1);
            cout << stepsRight << " " << red + 1 - stepsDown << '\n';
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


