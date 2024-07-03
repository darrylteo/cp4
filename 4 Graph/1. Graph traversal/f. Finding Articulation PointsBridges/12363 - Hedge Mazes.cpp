#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi dfs_num, dfs_low, dfs_parent, adjList[100005], bridgeAdjList[100005];
int dfsNumberCounter, belongCC[100005], CC;
vii bridges;

// standard code from book
inline void articulationPointAndBridge(int u) {
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
    for (auto v: adjList[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            articulationPointAndBridge(v);
            if (dfs_low[v] > dfs_num[u]) {
                bridges.emplace_back(u, v);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

void dfs(int u) {
    belongCC[u] = CC;
    for (auto v: bridgeAdjList[u]) {
        if (belongCC[v] == -1) {
            dfs(v);
        }
    }
}

// find all bridges, make a new graph with only bridges and mark which CC each bridge network belongs to
// if both start and end is in same CC, then it's a valid maze

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, Q;
    while(cin >> R >> C >> Q, R){
        dfsNumberCounter = 0;
        dfs_num.assign(R + 1, -1);
        dfs_low.assign(R + 1, 0);
        dfs_parent.assign(R + 1, 0);
        bridges.clear();
        memset(adjList, 0, sizeof adjList);
        for (int i = 0; i < C; ++i) {
            int A, B;
            cin >> A >> B;
            adjList[A].push_back(B);
            adjList[B].push_back(A);
        }
        // get all bridges
        for (int i = 1; i <= R; ++i) {
            if (dfs_num[i] == -1) {
                articulationPointAndBridge(i);
            }
        }
        // make a new graph with only bridges
        memset(bridgeAdjList, 0, sizeof bridgeAdjList);
        for (auto &bridge: bridges) {
            bridgeAdjList[bridge.first].push_back(bridge.second);
            bridgeAdjList[bridge.second].push_back(bridge.first);
        }

        // mark which CC each bridge network belongs to
        memset(belongCC, -1, sizeof belongCC);
        CC = 0;
        for (int i = 1; i <= R; ++i) {
            if (belongCC[i] == -1) {
                dfs(i);
                CC++;
            }
        }

        // answer queries
        for (int i = 0; i < Q; ++i) {
            int A, B;
            cin >> A >> B;
            if (belongCC[A] == belongCC[B]) {
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        }
        cout << "-\n";
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
