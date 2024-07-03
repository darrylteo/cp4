#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi dfs_num, dfs_low, dfs_parent, articulation_vertex, adjList[100005];
int dfsNumberCounter, dfs_roots[100005];

inline void articulationPointAndBridge(int u) {
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
    for (auto v: adjList[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u]) articulation_vertex[u]++; // just modify here
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M, N) {
        dfsNumberCounter = 0;
        dfs_num.assign(N, -1);
        dfs_low.assign(N, 0);
        dfs_parent.assign(N, 0);
        articulation_vertex.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            adjList[i].clear();
            dfs_roots[i] = 0;
        }

        int u, v;
        while (cin >> u >> v, u != -1 && v != -1) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (int i = 0; i < N; ++i) {
            if (dfs_num[i] == -1) {
                dfs_roots[i] = 1;
                articulationPointAndBridge(i);
            }
        }

        // add 1 to non-roots since its predecessor will be an extra disconnected component
        for (int i = 0; i < N; ++i) {
            if (!dfs_roots[i]) {
                articulation_vertex[i]++;
            }
        }

        vector<pair<int, int>> ans;
        for (int i = 0; i < N; ++i) {
            ans.emplace_back(i, articulation_vertex[i]);
        }
        sort(ans.begin(), ans.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        for (int i = 0; i < M; ++i) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



