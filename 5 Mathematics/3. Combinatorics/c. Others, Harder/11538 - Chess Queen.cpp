#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// ref: https://algorithmist.com/wiki/UVa_11538_-_Chess_Queen
// uses the sum of square formula... secondary school days oh no

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull r, c;
    while (cin >> r >> c, r) {
        ull ans = 0;

        // diagonal moves
        ull mini = min(r, c), maxi = max(r, c);
        mini--;
        ans = mini * (mini + 1) * (mini - 1) / 3; // counts the increasing/decreasing size diagonals
        ans *= 2;
        mini++;
        ans += (mini - 1) * mini * (maxi - mini + 1); // the same size diagonals
        ans *= 2;

        ans += r * (r - 1) * c; // choose any 2 spots in the row
        ans += c * (c - 1) * r; // choose any 2 spots in the column

        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


