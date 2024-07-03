#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define inf 1000000000000000 // 10^15

ll memo[105][105][2]; // l, r, turn. store score a - b
vector<ll> cum;

ll dp(int l, int r, int turn) {
    if (l > r) return 0;
    if (memo[l][r][turn] != -1) return memo[l][r][turn];

    ll ans;
    if (turn == 0) { // a's turn (tries to win)
        ans = -inf;
        // try picking all left and right arrays
        for (int i = l; i <= r; ++i) {
            ll a = cum[r] - (i == 0 ? 0 : cum[i - 1]) + dp(l, i - 1, 1); // a keeps r to i (right half)
            ll b = cum[i] - (l == 0 ? 0 : cum[l - 1]) + dp(i + 1, r, 1); // a keeps l to i (left half)
            ans = max(ans, max(a, b));
        }
    } else { // b's turn (tries to make a lose)
        ans = inf;
        // try picking all left and right arrays
        for (int i = l; i <= r; ++i) {
            ll a = -(cum[r] - (i == 0 ? 0 : cum[i - 1])) + dp(l, i - 1, 0); // b keeps r to i (right half)
            ll b = -(cum[i] - (l == 0 ? 0 : cum[l - 1])) + dp(i + 1, r, 0); // b keeps l to i (left half)
            ans = min(ans, min(a, b));
        }
    }
    return memo[l][r][turn] = ans;
}

// a little annoying to debug with all the +1 and -1...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N, N) {
        vector<ll> v(N);
        for (int i = 0; i < N; ++i) cin >> v[i];
        cum.assign(N, 0);
        cum[0] = v[0];
        for (int i = 1; i < N; ++i) cum[i] = cum[i - 1] + v[i];
        memset(memo, -1, sizeof(memo));
        cout << dp(0, N - 1, 0) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

