#include <bits/stdc++.h>

using namespace std;

// block top row such that we have a 4x6 grid
// mirror opponent moves in both axis "origin" at 2,3
// kinda like a "perfect matching" described a few sections earlier

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc, a, b, c, d;
    string s;
    cin >> tc;
    while (tc--) {
        cout << "1 1 1 6" << endl << flush;
        while (cin >> s) {
            if (s == "GAME") break;
            cin >> a >> b >> c >> d;
            if (a == 1) a = 2; // important. there is no row (7-1=6) in the grid
            cout << 7 - c << ' ' << 7 - d << ' ' << 7 - a << ' ' << 7 - b << endl << flush;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
