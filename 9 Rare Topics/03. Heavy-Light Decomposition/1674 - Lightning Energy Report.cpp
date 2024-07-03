#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi visited, parent, LCA;
vector<vi> adj;
vector<vii> Q;

inline int findp(int x) {
    return parent[x] == x ? x : findp(parent[x]);
}

void tarjan(int u, int p) { // rooted-tree.
    parent[u] = u;
    for (int v: adj[u]) {
        if (v == p) continue;
        tarjan(v, u);
        parent[findp(v)] = u;
    }
    visited[u] = 1;
    for (auto &i: Q[u]) {
        if (visited[i.second]) {
            LCA[i.first] = findp(i.second); // LCA of i.first (query idx) is the "maximum" parent up to this point in recursion
        }
    }
}

int dfs(int u, int p, vi &weight) {
    int sum = weight[u];
    for (int v: adj[u]) {
        if (v == p) continue;
        sum += dfs(v, u, weight);
    }
    return weight[u] = sum;
}

// ref: https://morris821028.github.io/2014/12/02/uva-1674/

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, x, y;
    int T, cases = 0;
    cin >> T;
    while (T--) {
        cin >> n;
        adj.assign(n, vi());
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        visited.assign(n, 0), parent.assign(n, 0);
        Q.assign(n, vii());
        vi extra(n), weight(n);

        cin >> m;
        vi X(m), Y(m), K(m);
        LCA.assign(m, 0); // LCA of i-th query.
        for (int i = 0; i < m; i++) {
            cin >> X[i] >> Y[i] >> K[i];
            Q[X[i]].emplace_back(i, Y[i]);
            Q[Y[i]].emplace_back(i, X[i]);
        }
        tarjan(0, -1);
        for (int i = 0; i < m; i++) {
            extra[LCA[i]] += K[i];
            weight[X[i]] += K[i];
            weight[Y[i]] += K[i];
            weight[LCA[i]] -= 2 * K[i];
        }
        dfs(0, -1, weight);

        cout << "Case #" << ++cases << ":" << endl;
        for (int i = 0; i < n; i++) cout << weight[i] + extra[i] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}