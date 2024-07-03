#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define MOD 1000000009

int N, K, T;
ll memo[105][5005];

ll dp(int idx, int sum) {
    if (idx == N) {
        if (sum == T) return 1;
        else return 0;
    }
    ll &ans = memo[idx][sum];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 1; i <= K; ++i) {
        ans += dp(idx + 1, sum + i);
        ans %= MOD;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N >> K >> T;
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

