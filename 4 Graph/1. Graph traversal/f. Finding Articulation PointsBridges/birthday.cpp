#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi dfs_num, dfs_low, dfs_parent, adjList[1005];
int dfsNumberCounter;
vii bridges;

// standard code from book
inline void articulationPointAndBridge(int u) {
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
    for (auto v: adjList[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            articulationPointAndBridge(v);
            if (dfs_low[v] > dfs_num[u]) {
                bridges.emplace_back(min(u, v), max(u, v)); // sorted
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

// direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m, n) {
        dfsNumberCounter = 0;
        dfs_num.assign(n, -1);
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0);
        bridges.clear();
        memset(adjList, 0, sizeof adjList);
        for (int i = 0; i < m; ++i) {
            int A, B;
            cin >> A >> B;
            adjList[A].push_back(B);
            adjList[B].push_back(A);
        }
        // get all bridges
        for (int i = 0; i < n; ++i) {
            if (dfs_num[i] == -1) {
                articulationPointAndBridge(i);
            }
        }
        // print
        if (bridges.empty()) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
