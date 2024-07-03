#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi AL[505];
int match[505], vis[505];

inline int Aug(int L) {
    if (vis[L]) return 0;                          // L visited, return 0
    vis[L] = 1;
    for (auto &R: AL[L])
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L;                              // flip status
            return 1;                                  // found 1 matching
        }
    return 0;                                      // no matching
}

// direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        for (auto &a: AL) a.clear();
        memset(match, -1, sizeof match);
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int y;
                cin >> y;
                if (y) AL[i].push_back(j);
            }
        }

        int MCBM = 0;
        for (int i = 0; i < n; ++i) {                        // (in random order)
            memset(vis, 0, sizeof vis);                  // reset before each recursion
            MCBM += Aug(i);                              // try to match f
        }
        cout << "Case " << cases << ": a maximum of " << MCBM << " nuts and bolts can be fitted together\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

