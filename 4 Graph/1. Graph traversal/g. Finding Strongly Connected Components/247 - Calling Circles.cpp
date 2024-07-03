#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum { UNVISITED = -1 };

int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, visited, AL[30];                 // global variables
vector<vector<int>> SCCs;
stack<int> St;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;    // dfs_low[u]<=dfs_num[u]
    dfsNumberCounter++;                            // increase counter
    St.push(u);                                    // remember the order
    visited[u] = 1;
    for (int &v : AL[u]) {
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v])                              // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {                // a root/start of an SCC
        ++numSCC;                                    // when recursion unwinds
        vi SCC;
        while (true) {
            int v = St.top(); St.pop(); visited[v] = 0;
            SCC.push_back(v);
            if (u == v) break;
        }
        SCCs.push_back(SCC);
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, caseNo = 0;
    while (cin >> N >> M, N) {
        for (int i = 0; i < N; ++i) AL[i].clear();
        set<string> names;
        map<string, int> name_to_id;
        int id = 0;
        while (M--) {
            string a, b;
            cin >> a >> b;
            if (names.insert(a).second) {
                name_to_id[a] = id++;
            }
            if (names.insert(b).second) {
                name_to_id[b] = id++;
            }
            AL[name_to_id[a]].push_back(name_to_id[b]); // directed
        }

        // run Tarjan's SCC code here
        dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0); visited.assign(N, 0);
        while (!St.empty()) St.pop();
        dfsNumberCounter = numSCC = 0;
        for (int u = 0; u < N; ++u)
            if (dfs_num[u] == UNVISITED)
                tarjanSCC(u);

        // output SCCs
        if (caseNo++) cout << "\n";
        cout << "Calling circles for data set " << caseNo << ":\n";
        for (auto &SCC : SCCs) {
            for (int i = 0; i < SCC.size(); ++i) {
                if (i) cout << ", ";
                int idPrint = SCC[i];
                for (auto &p : name_to_id) {
                    if (p.second == idPrint) {
                        cout << p.first;
                        break;
                    }
                }
            }
            cout << "\n";
        }
        SCCs.clear();
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}