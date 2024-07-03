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

// to be equivalent, need at least 1 outdegree and 1 indegree per SCC
// answer will be max(no outdegree, no indegree)

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
        bool SCCOutDegree[SCCIdx];
        memset(SCCInDegree, 0, sizeof SCCInDegree);
        memset(SCCOutDegree, 0, sizeof SCCOutDegree);
        for (int u = 0; u < N; ++u) {
            for (int &v: AL[u]) {
                if (SCCIndices[u] != SCCIndices[v]) { // u goes into v. SCCIndices represents SCC number/color
                    SCCInDegree[SCCIndices[v]] = true;
                    SCCOutDegree[SCCIndices[u]] = true;
                }
            }
        }

        // 1 SCC only would have 0 in and out degree so it would normally be counted as 1 (wrong)
        if (SCCIdx == 1) {
            cout << 0 << '\n';
            continue;
        }

        int SCCInDegreeCount = 0;
        int SCCOutDegreeCount = 0;
        for (int i = 0; i < SCCIdx; ++i) {
            if (!SCCInDegree[i]) SCCInDegreeCount++;
            if (!SCCOutDegree[i]) SCCOutDegreeCount++;
        }
        cout << max(SCCInDegreeCount, SCCOutDegreeCount) << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}