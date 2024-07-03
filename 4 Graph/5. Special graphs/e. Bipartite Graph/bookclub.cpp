#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// more or less standard qn
// see if each person can be paired to a book
// some code from cp4 book

vi AL[20005];
int match[20005], vis[20005];

inline int Aug(int L) {
    if (vis[L]) return 0;                          // L visited, return 0
    vis[L] = 1;
    for (auto &R : AL[L])
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L;                              // flip status
            return 1;                                  // found 1 matching
        }
    return 0;                                      // no matching
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    unordered_set<int> freeV;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        AL[a].push_back(b+10000); // 0-9999 for person (left), 10000-19999 for books (right)
        freeV.insert(a);
    }
    memset(match, -1, sizeof match);
    int MCBM = 0;
    for (auto &f : freeV) {                        // (in random order)
        memset(vis, 0, sizeof vis);                  // reset before each recursion
        MCBM += Aug(f);                              // try to match f
    }
    if (MCBM == n) cout << "YES\n";
    else cout << "NO\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

