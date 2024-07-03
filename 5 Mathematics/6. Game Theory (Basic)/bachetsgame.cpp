#include <bits/stdc++.h>

using namespace std;

// note that on udebug test cases are very very slow
// but probably weak test cases on uva and kattis since this code passed

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> v(m);
        for (int i = 0; i < m; i++) cin >> v[i];
        bitset<1000001> dp;
        dp[0] = true; // true means ollie wins. if 0 stone stan can't make a move and ollie wins
        // if stan can reach an ollie state he will win
        for (int i = 1; i <= n; i++) {
            int found = false;
            for (int j = 0; j < m; j++) {
                if (i - v[j] >= 0 && dp[i - v[j]]) {
                    found = true;
                    break;
                }
            }
            dp[i] = !found; // since found ollie state, stan wins
        }
        cout << (!dp[n] ? "Stan wins" : "Ollie wins") << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}