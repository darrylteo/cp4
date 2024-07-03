#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

// always go as diagonal as possible, which is (n-2) steps from start
// then go down and diagonal back (n-3) steps... until 1 step diagonal
// this pattern is repeated on other triangle.
// e.g. for n = 5. we have diagonals = 3 (main diag) + (2 + 1) (lower triangle) + (2 + 1) (upper triangle)
// number of diagonals forms a square of size 3 (or n-2 in general case)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        double ans;
        if (x == 1) {
            ans = 0;
        } else if (x == 2) {
            ans = 4;
        } else {
            int diags = (x - 2) * (x - 2);
            ans = (x * x - diags) + (diags * sqrt(2));
        }

        cout << fixed << setprecision(3) << ans << '\n';
        if (n) cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


