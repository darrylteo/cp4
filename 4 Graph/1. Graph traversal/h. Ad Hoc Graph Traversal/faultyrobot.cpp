#include <bits/stdc++.h>

using namespace std;

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_4_Graph/Graph_Traversal/kattis_faultyrobot.cpp
// forced can go i -> j or i + n -> j + n (both does not consume a bug)
// unforced can go i -> j + n (and consume a bug so can no longer use any unforced paths)
// start dfs at 0 (qn didn't state)

vector<int> adj[2005];
int visited[2005], hasForce[2005];

void dfs(int u) {
    visited[u] = 1;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        if (u > 0) {
            u--;
            v--;
            adj[u].push_back(v + n);
        } else {
            u = -u - 1;
            v--;
            adj[u].push_back(v);
            adj[u + n].push_back(v + n);
            hasForce[u] = 1; // visiting here is ok
            // visiting an edge with no force means u might be stuck (also since it is possible to make 0 buggy moves... see example 2)
        }
    }

    dfs(0);
    unordered_set<int> s;
    for (int j = 0; j < n; ++j) {
        if (visited[j] && !hasForce[j]) {
            s.insert(j);
        }
    }
    for (int j = n; j < 2 * n; ++j) {
        if (visited[j] && !hasForce[j - n]) {
            s.insert(j - n);
        }
    }
    cout << s.size() << "\n";


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

