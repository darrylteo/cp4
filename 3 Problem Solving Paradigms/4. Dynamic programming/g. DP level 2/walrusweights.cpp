#include <bits/stdc++.h>

using namespace std;

int weights[1005], memo[1005][2005];  // idx, total weight, stores diff from 1000
int n, bestDiff = 10000, bestWeight = 0;

int dp(int idx, int total) {
    if (idx == n) {
        if (abs(total - 1000) < bestDiff) {
            bestDiff = abs(total - 1000);
            bestWeight = total;
        } else if (abs(total - 1000) == bestDiff) {
            bestWeight = max(bestWeight, total);
        }
        return abs(total - 1000);
    }
    if (total > 2000) return 1000000;
    int &ans = memo[idx][total];
    if (ans != -1) return ans;
    return ans = min(dp(idx + 1, total), dp(idx + 1, total + weights[idx]));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> weights[i];
    memset(memo, -1, sizeof memo);
    dp(0, 0);
    cout << bestWeight << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


