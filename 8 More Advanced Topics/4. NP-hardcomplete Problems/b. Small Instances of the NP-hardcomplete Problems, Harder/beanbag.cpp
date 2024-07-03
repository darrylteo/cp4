#include <bits/stdc++.h>

using namespace std;

#define LSONE(s) ((s) & -(s))

int B, F; // beans, farmers
vector<int> b, f; // beans, farmers (bitset)
int memo[1 << 20]; // beans (1 means farmer give him this bean). nice optimization to not include farmers!

// can assume he has unlimited trips to farmers but they give him bad beans.
// e.g. in sample input 2, he can visit each farmer 100 times, but they will give him bean 2. so he still lacks 1 and 3.
// just check the worst case for the beans the farmer will give him.

int dp(int i, int mask) {
    if (i == F) {
        int sum = 0;
        for (int j = 0; j < B; j++) {
            if (!(mask & (1 << j))) sum += b[j];
        }
        return sum;
    }
    if (memo[mask] != -1) return memo[mask];
    int ans = 0;
    if (mask & f[i]) ans = dp(i + 1, mask);
    else {
        int farmer = f[i];
        while (farmer) {
            int bean = LSONE(farmer);
            farmer -= bean;
            ans = max(ans, dp(i + 1, mask | bean));
        }
    }

    return memo[mask] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> B;
    b.resize(B);
    for (int i = 0; i < B; i++) cin >> b[i];
    cin >> F;
    f.resize(F);
    for (int i = 0; i < F; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            f[i] |= (1 << (x - 1));
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}