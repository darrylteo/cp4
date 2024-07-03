#include <bits/stdc++.h>

using namespace std;

// acrons are obvious, just check which letter not in edge list
// we find trees 1st, later then check if cycle exists https://www.geeksforgeeks.org/count-number-trees-forest/
// well the cycles are just distraction, not needed in solution

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited) {
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}

int countTrees(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    int res = 0;
    for (int u = 0; u < V; u++) {
        if (!visited[u] && adj[u].size() > 0) { // if size 0 could be acorn or doesn't exist
            DFSUtil(u, adj, visited);
            res++;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        set<int> nodes; // just for counting acorns
        vector<int> adj[26];
        string s;
        while (cin >> s && s[0] != '*') {
            addEdge(adj, s[1] - 'A', s[3] - 'A');
            nodes.insert(s[1] - 'A');
            nodes.insert(s[3] - 'A');
        }
        int trees = countTrees(adj, 26);
        int nodesCount = nodes.size();
        cin >> s;
        int acorns = s.size() / 2 + 1 - nodesCount;
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
