#include <bits/stdc++.h>

using namespace std;

int N;
int adj[15], memo[1 << 15]; // adj for friends he's ok with. memo if impossible or not

int dp(int mask) {
    if (mask == 0) return 1; // all paired up
    if (memo[mask] != -1) return memo[mask];

    int ans = 0;
    for (int p1 = 0; p1 < N; ++p1)
        if (mask & (1 << p1)) {
            for (int p2 = p1 + 1; p2 < N; ++p2)
                if (mask & (1 << p2) && (adj[p1] & (1 << p2))) {
                    for (int p3 = p2 + 1; p3 < N; ++p3)
                        if (mask & (1 << p3) && (adj[p1] & (1 << p3)) && (adj[p2] & (1 << p3))) {
                            int newMask = mask ^ (1 << p1) ^ (1 << p2) ^ (1 << p3);
                            ans = max(ans, dp(newMask));
                        }
                }
        }
    return memo[mask] = ans;
}

// just a 5 min edit away from uva 11088

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x, x) {
        map<string, int> mp;
        memset(adj, 0, sizeof adj);
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < x; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            if (mp.find(s1) == mp.end()) mp[s1] = (int) mp.size();
            if (mp.find(s2) == mp.end()) mp[s2] = (int) mp.size();
            adj[mp[s1]] |= 1 << mp[s2];
            adj[mp[s2]] |= 1 << mp[s1];
        }
        N = (int) mp.size();
        cout << (dp((1 << N) - 1) ? "possible\n" : "impossible\n");
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}