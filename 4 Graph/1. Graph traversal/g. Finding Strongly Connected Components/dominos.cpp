#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1
};

int dfsNumberCounter, SCCIdx, SCCIndices[100005];
vi dfs_num, dfs_low, visited, AL[100005];                 // global variables
stack<int> St;

inline void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;    // dfs_low[u]<=dfs_num[u]
    dfsNumberCounter++;                            // increase counter
    St.push(u);                                    // remember the order
    visited[u] = 1;
    for (int &v: AL[u]) {
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v])                              // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {                // a root/start of an SCC
        while (true) {
            int v = St.top();
            St.pop();
            SCCIndices[v] = SCCIdx; // modify here
            visited[v] = 0;
            if (u == v) break;
        }
        SCCIdx++;
    }
}

// not CC because it is directed
// number each SCC and check if it has external in edge

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cin >> N >> M;
        for (int i = 0; i < N; ++i) AL[i].clear();
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            AL[u].push_back(v); // out edge
        }

        // run Tarjan's SCC code here
        dfs_num.assign(N, UNVISITED);
        dfs_low.assign(N, 0);
        visited.assign(N, 0);
        while (!St.empty()) St.pop();
        dfsNumberCounter = SCCIdx = 0;
        for (int u = 0; u < N; ++u)
            if (dfs_num[u] == UNVISITED)
                tarjanSCC(u);

        // check if each SCC has external in edge
        bool SCCInDegree[SCCIdx];
        memset(SCCInDegree, 0, sizeof SCCInDegree);
        for (int u = 0; u < N; ++u) {
            for (int &v: AL[u]) {
                if (SCCIndices[u] != SCCIndices[v]) { // u goes into v
                    SCCInDegree[SCCIndices[v]] = true;
                }
            }
        }
        cout << SCCIdx - accumulate(SCCInDegree, SCCInDegree + SCCIdx, 0) << '\n';

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}