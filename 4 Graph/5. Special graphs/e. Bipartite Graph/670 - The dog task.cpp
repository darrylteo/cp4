#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi AL[205]; // 0-99 for human, 100-199 for dog
int match[205], vis[205];

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

// if not told to do MCBM idk what algo would be good also

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
        vii human(n), dog(m);
        for (int i = 0; i < n; ++i) {
            cin >> human[i].first >> human[i].second;
        }
        for (int i = 0; i < m; ++i) {
            cin >> dog[i].first >> dog[i].second;
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                int hx1 = human[i].first, hy1 = human[i].second;
                int hx2 = human[i + 1].first, hy2 = human[i + 1].second;
                int dx = dog[j].first, dy = dog[j].second;
                // human: p1 - p2, dog: p1 - attraction - p2
                double hdist = sqrt((hx1 - hx2) * (hx1 - hx2) + (hy1 - hy2) * (hy1 - hy2));
                double ddist = sqrt((hx1 - dx) * (hx1 - dx) + (hy1 - dy) * (hy1 - dy)) +
                               sqrt((hx2 - dx) * (hx2 - dx) + (hy2 - dy) * (hy2 - dy));
                if (hdist * 2 >= ddist) { // if dog doesn't take too long
                    AL[i].push_back(j + 100);
                }
            }
        }
        int MCBM = 0;
        for (int i = 0; i < n; ++i) {                        // (in random order)
            memset(vis, 0, sizeof vis);                  // reset before each recursion
            MCBM += Aug(i);                              // try to match f
        }

        vii dogPath;
        for (int i = 100; i < 100 + m; ++i) {
            if (match[i] != -1) {
                dogPath.emplace_back(match[i], i - 100);
            }
        }
        cout << MCBM + n << '\n';
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                cout << human[i].first << ' ' << human[i].second << '\n';
                continue;
            }
            cout << human[i].first << ' ' << human[i].second << ' ';
            for (auto &p: dogPath) {
                if (p.first == i) {
                    cout << dog[p.second].first << ' ' << dog[p.second].second << ' ';
                }
            }
        }
        if (cases != T) cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

