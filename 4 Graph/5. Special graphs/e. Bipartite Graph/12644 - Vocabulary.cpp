#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vi AL[505];
int match[1005], vis[1005];

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

inline int jackWin(vi &jack, vi &jill) {
    for (int i = 0; i < 26; ++i) {
        if (jack[i] < jill[i]) return 0;
    }
    return 1;
}

// direct application if told is an MCBM problem

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vvi jack(n, vi(26, 0)), jill(m, vi(26, 0));
        for (int i = 0; i < 505; ++i) AL[i].clear();
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (char c: s) {
                jack[i][c - 'a']++;
            }
        }
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            for (char c: s) {
                jill[i][c - 'a']++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (jackWin(jack[i], jill[j])) {
                    AL[i].push_back(n + j);
                }
            }
        }

        int MCBM = 0;
        memset(match, -1, sizeof match);
        for (int L = 0; L < n; L++) {
            memset(vis, 0, sizeof vis);
            MCBM += Aug(L);
        }
        cout << MCBM << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

