#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<string, int> mapper;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mapper[s] = i + 1;
    }
    mapper["English"] = 0;
    vii adj[n + 1];
    for (int i = 0; i < m; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        adj[mapper[u]].emplace_back(mapper[v], w);
        adj[mapper[v]].emplace_back(mapper[u], w);
    }
    queue<int> q;
    q.push(0);
    vi dist(n + 1, 1e9), cost(n + 1, 1e9);
    dist[0] = 0;
    long long ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v: adj[u]) {
            if (dist[v.first] == 1e9 || dist[v.first] == dist[u] + 1) { // new node or same level
                q.push(v.first);
                dist[v.first] = dist[u] + 1;
                cost[v.first] = min(cost[v.first], v.second);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1e9) {
            cout << "Impossible" << endl;
            return 0;
        }
        ans += cost[i];
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}