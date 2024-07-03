#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int gates[1005], inEdges[1005];
vector<int> adj[1005];
pll memo[1005];

pll dp(int u) {
    if (adj[u].empty()) {
        if (gates[u] == 1) return {1, 1};
        return {0, 1};
    }
    if (memo[u].first != -1) return memo[u];
    pll ans = {0, 0};
    for (int v : adj[u]) {
        ans.first += dp(v).first;
        ans.second += dp(v).second;
    }
    return memo[u] = ans;
}

// this section so much easier than previous ones... finally a break.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, u, v, g;
    cin >> n >> m;
    while (m--){
        cin >> u >> v;
        adj[u].push_back(v);
        inEdges[v]++;
    }
    cin >> g;
    while (g--) {
        cin >> u;
        gates[u] = 1;
    }
    memset(memo, -1, sizeof(memo));
    pll ans = {0,0};
    for (int i = 0; i < n; ++i) {
        if (inEdges[i] == 0) {
            pll res = dp(i);
            ans.first += res.first;
            ans.second += res.second;
        }
    }
    cout << "winning paths " << ans.first << "\n";
    cout << "total paths " << ans.second << "\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
