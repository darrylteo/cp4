#include <bits/stdc++.h>

using namespace std;

#define maxn 105
// element to left of blank interval, right of blank interval, length of blank interval.
// element either 0 (none), 1 (X), 2 (O)
int grundy[3][3][maxn];
bool vis[3][3][maxn];
string s;

int dfs(int ll, int rr, int n) {
    if (n <= 0) return grundy[ll][rr][n] = 0;
    if (vis[ll][rr][n]) return grundy[ll][rr][n];
    vis[ll][rr][n] = true;
    bool ok[maxn];
    memset(ok, 0, sizeof(ok));
    for (int i = 1; i <= n; i++) {
        for (int neww = 1; neww <= 2; neww++) {
            if (i == 1 && ll == neww) continue; // e.g. X....O, cannot (X) at [1] and cannot (O) at [4]
            if (i == n && rr == neww) continue;
            int l = dfs(ll, neww, i - 1);
            int r = dfs(neww, rr, n - i);
            ok[l ^ r] = true;
        }
    }
    // search until get mex.
    for (int i = 0; i < maxn; i++) {
        if (!ok[i]) return grundy[ll][rr][n] = i;
    }
    return -1;
}

void solve() {
    int ll = 0, rr = 0;
    int XOR = 0, turn = 0;

    int now = 0;
    for (char c: s) {
        if (c == '.') now++;
        else {
            rr = c == 'O' ? 2 : 1;
            XOR ^= dfs(ll, rr, now);
            ll = rr;
            now = 0;
            turn++;
        }
    }
    XOR ^= dfs(ll, 0, now); // last blank interval
    XOR = turn % 2 ? !XOR : XOR; // to count the number of turns (i.e. circles + crosses) since we duno if alice or computer turn next
    if (XOR) cout << "Possible." << endl;
    else cout << "Impossible." << endl;
}

// similar to 10561 - Treblecross
// don't reset grundy since we put constraints (ll, rr) such that if it works for one case it will work for all

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        solve();
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
