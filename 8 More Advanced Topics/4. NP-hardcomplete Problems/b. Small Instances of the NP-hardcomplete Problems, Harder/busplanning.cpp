#include <bits/stdc++.h>

using namespace std;

int N, K, C;
int adj[17], memo[1 << 17]; // adj for friends he's angry with. memo count least groups
map<string, int> mp;
map<int, string> mp2;

int ok(int mask) {
    while (mask) {
        int i = __builtin_ctz(mask);
        mask ^= 1 << i;
        if ((mask & adj[i]) != 0) return 0;
    }
    return 1;
}

int dp(int mask) {
    if (mask == 0) return 0; // all paired up
    if (memo[mask] != -1) return memo[mask];

    int ans = 1e9;
    for (int ss = mask; ss; ss = (ss - 1) & mask) {
        if (__builtin_popcount(ss) > C) continue; // if more than C people in group
        if (ok(ss)) ans = min(ans, dp(mask ^ ss) + 1);
    }
    return memo[mask] = ans;
}

// standard lazy way to print ans by running algorithm again. but this time mostly already saved in memo.
void printAns(int mask) {
    if (mask == 0) return;
    for (int ss = mask; ss; ss = (ss - 1) & mask) {
        if (__builtin_popcount(ss) > C) continue;
        if (ok(ss) && dp(mask) == dp(mask ^ ss) + 1) {
            for (int i = 0; i < N; ++i) {
                if (ss & (1 << i)) cout << mp2[i] << " ";
            }
            cout << endl;
            printAns(mask ^ ss);
            return;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> C;

    memset(adj, 0, sizeof adj);
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        mp[s] = i;
        mp2[i] = s;
    }
    for (int i = 0; i < K; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        adj[mp[s1]] |= 1 << mp[s2];
        adj[mp[s2]] |= 1 << mp[s1];
    }
    cout << dp((1 << N) - 1) << endl;
    printAns((1 << N) - 1);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}