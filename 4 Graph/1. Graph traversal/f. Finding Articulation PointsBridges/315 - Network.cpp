#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi dfs_num, dfs_low, dfs_parent, articulation_vertex, adjList[105];
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
    for (auto v: adjList[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = true;
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

    int N;
    while (cin >> N, N) {
        dfsNumberCounter = 0;
        dfs_num.assign(N, -1);
        dfs_low.assign(N, 0);
        dfs_parent.assign(N, 0);
        articulation_vertex.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            adjList[i].clear();
        }

        int u, v;
        while (cin >> u, u) {
            --u;
            string line;
            getline(cin, line);
            stringstream ss(line);
            while (ss >> v) {
                --v;
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        for (int i = 0; i < N; ++i) {
            if (dfs_num[i] == -1) {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (articulation_vertex[i]) ++ans;
        }
        cout << ans << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



