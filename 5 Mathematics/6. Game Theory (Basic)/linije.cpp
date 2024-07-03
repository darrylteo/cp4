#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi AL[1005];
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

// "MCBM" part comes from the fact we must do alternately horizontal and vertical lines
// if perfect match then mirko sure lose because there are even lines to draw. or can say whatever line mirko draw, slavo can draw a matching line
// for example if just 1 point (500, 500) it is perfect match. if mirko draw x=500, slavo has a y=500 to match. mirko lose
// else if not perfect, there is at least 1 odd length chain then mirko can choose to go on the odd one

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(match, -1, sizeof match);
    set<int> s;
    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        AL[x].push_back(500 + y);
        AL[500 + y].push_back(x);
        s.insert(x);
        s.insert(500 + y);
    }

    int MCBM = 0;
    for (int i = 1; i <= 500; ++i) {                        // (in random order)
        memset(vis, 0, sizeof vis);                  // reset before each recursion
        MCBM += Aug(i);                              // try to match f
    }
    if (2*MCBM != s.size()) cout << "Mirko";
    else cout << "Slavko";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

