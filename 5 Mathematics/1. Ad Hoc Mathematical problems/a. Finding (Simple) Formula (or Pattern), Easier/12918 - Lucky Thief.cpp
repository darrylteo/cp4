#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

// based on the 4 6 example.
// first key check door 1,2,3,4,5 (if none open it must be 6) = 5
// second key check door 1,2,3,4,5 minus the one that first key opened = 4
// third key check 3 door
// fourth key check 2 door
// sum = 5 + 4 + 3 + 2 = (5 + 2) * 4 / 2 = 14

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        long long x, y, ans;
        cin >> x >> y;
        cout << ((y - 1) + (y - x)) * x / 2 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


