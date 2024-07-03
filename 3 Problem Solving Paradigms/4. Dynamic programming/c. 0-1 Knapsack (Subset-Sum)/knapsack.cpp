#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2005;
const int MAX_W = 2005;

// note: bottom up approach is about 2x faster for this problem

int C, N, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW) {
    if ((id == N) || (remW == 0)) return 0;        // two base cases
    int &ans = memo[id][remW];
    if (ans != -1) return ans;                     // computed before
    if (W[id] > remW) return ans = dp(id+1, remW); // no choice, skip
    return ans = max(dp(id+1, remW),               // has choice, skip
                     V[id]+dp(id+1, remW-W[id]));  // or take
}

void printDp() {
    int wt = C, cnt = 0;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (dp(i, wt) == dp(i+1, wt)) continue;
        ans.push_back(i);
        wt -= W[i];
        cnt++;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (cin >> C >> N) {
        for (int i = 0; i < N; i++) cin >> V[i] >> W[i];
        memset(memo, -1, sizeof memo);
        dp(0, C); // answer stored in memo[0][C]
        printDp();
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
