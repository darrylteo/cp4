#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1
};

int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, visited, AL[1005];                 // global variables
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
        ++numSCC;                                    // when recursion unwinds
        while (true) {
            int v = St.top();
            St.pop();
            visited[v] = 0;
            if (u == v) break;
        }
    }
}

// hard to identify CC vs SCC... the keyword pointing to use of SCC is "trust each other" (?)
// direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M, N) {
        for (int i = 0; i < N; ++i) AL[i].clear();
        unordered_map<string, int> name_to_id;
        for (int i = 0; i < N; ++i) {
            string name;
            getline(cin >> ws, name);
            name_to_id[name] = i;
        }
        for (int i = 0; i < M; ++i) {
            string name1, name2;
            getline(cin >> ws, name1);
            getline(cin >> ws, name2);
            AL[name_to_id[name1]].push_back(name_to_id[name2]);
        }

        // run Tarjan's SCC code here
        dfs_num.assign(N, UNVISITED);
        dfs_low.assign(N, 0);
        visited.assign(N, 0);
        while (!St.empty()) St.pop();
        dfsNumberCounter = numSCC = 0;
        for (int u = 0; u < N; ++u)
            if (dfs_num[u] == UNVISITED)
                tarjanSCC(u);

        cout << numSCC << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}