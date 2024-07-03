#include <bits/stdc++.h>

using namespace std;

// learning bottom up from https://www.pinghenotes.com/UVa-11420-Chest-of-Drawers/

long long memo[67][67][2]; // numDrawers, numLocked, topLocked

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s;
    // if numDrawers is 1 and numLocked is 1,and top is locked this is one successful combination
    memo[1][1][1] = 1;
    // if numDrawers == 1 and numLocked == 0, and top is not locked this is one successful combination
    memo[1][0][0] = 1;
    // no other base cases for 1 drawer

    for (int i = 2; i < 66; ++i) {
        // curr i-1 drawers and none locked and curr top not locked.
        // adding a new drawer on top total i drawers. add cases for adding a new unlocked drawer + locked
        // covers the special case of j=0
        memo[i][0][0] = memo[i - 1][0][0] + memo[i - 1][1][1];
        for (int j = 1; j <= i; ++j) {
            // adding an unlocked drawer. if prev top unlocked, adding unlocked same j.
            // if prev top locked, and it had j+1 locked, adding unlocked on top make locked become j only
            memo[i][j][0] = memo[i - 1][j][0] + memo[i - 1][j + 1][1];
            // adding locked drawer. no matter prev locked or nt we will gain +1 locked drawer so from j-1 to j
            memo[i][j][1] = memo[i - 1][j - 1][0] + memo[i - 1][j - 1][1];
        }
    }

    while (cin >> n >> s, n > 0) {
        cout << memo[n][s][0] + memo[n][s][1] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

