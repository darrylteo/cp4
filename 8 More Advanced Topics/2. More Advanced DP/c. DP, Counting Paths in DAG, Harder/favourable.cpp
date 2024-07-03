#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll memo[405];
vector<vector<int>> adj(405);

ll dp(int u) {
    if (u == 401) return 1;
    if (u == 402) return 0;
    if (memo[u] != -1) return memo[u];
    memo[u] = 0;
    for (int v : adj[u]) {
        memo[u] += dp(v);
    }
    return memo[u];
}

// let pg 401 = favourably, 402 = catastrophically

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        adj.assign(405, vector<int>());
        while (n--) {
            int u, v;
            string s;
            cin >> u >> s;
            if (s == "favourably") {
                adj[u].push_back(401);
                continue;
            }
            if (s == "catastrophically") {
                adj[u].push_back(402);
                continue;
            }
            v = stoi(s);
            adj[u].push_back(v);
            cin >> v;
            adj[u].push_back(v);
            cin >> v;
            adj[u].push_back(v);
        }
        memset(memo, -1, sizeof(memo));
        cout << dp(1) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
