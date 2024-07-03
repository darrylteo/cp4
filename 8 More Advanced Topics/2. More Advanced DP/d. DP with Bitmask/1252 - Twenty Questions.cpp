#include <bits/stdc++.h>

using namespace std;

vector<int> world;
int memo[1 << 11][1 << 11], n, m;

inline int dp(int Q, int A) {
    if (memo[Q][A] != -1) return memo[Q][A];

    int nn = 0;
    for (int i : world) { // check which objects match ans based on qns we asked
        if ((Q & i) == A) { // get info only from qns asked
            nn++;
        }
    }

    if (nn <= 1) return memo[Q][A] = 0; // good case

    int ans = 1e9;
    for (int i = 0; i < m; ++i) {
        if ((Q & (1 << i)) == 0) { // if we haven't asked this qn
            ans = min(ans, max(dp(Q | (1 << i), A), dp(Q | (1 << i), A | (1 << i))) + 1);
        }
    }

    return memo[Q][A] = ans;
}


// ref: https://github.com/ajahuang/UVa/blob/master/UVa%201252%20-%20Twenty%20Questions.cpp
// initially just selected j cols, and checked if all diff. i.e. ask same questions for all objects
// but it's wrong since u can branch and ask diff questions based on the remaining objects left

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> m >> n, m) {
        if (n == 1) {
            cin >> s; // clear the input
            cout << 0 << endl;
            continue;
        }

        world.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (char c: s) {
                world[i] = (world[i] << 1) | (c == '1');
            }
        }
        memset(memo, -1, sizeof(memo));
        cout << dp(0, 0) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
