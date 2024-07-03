#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> inDegree, inDegree1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    adj.resize(V);
    inDegree.resize(V, 0);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    // save for later
    inDegree1 = inDegree;
    // find root
    int root = -1, bad = 0;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            if (root == -1) {
                root = i;
            } else {
                bad = 1;
                break;
            }
        }
    }
    if (bad) {
        cout << "back to the lab\n";
        return 0;
    }
    // bfs and get longest path (standard code. kahn's algorithm)
    queue<int> q;
    q.push(root);
    vector<int> dist(V, 1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            dist[v] = dist[u] + 1;
            if (--inDegree[v] == 0) q.push(v);
        }
    }
    if (*max_element(dist.begin(),dist.end()) != V) { // no path that includes all elements
        cout << "back to the lab\n";
        return 0;
    }
    // after testing, only 1 path exists if longest path includes all elements
    priority_queue<int, vector<int>> pq1;
    pq1.push(root);
    while (!pq1.empty()) {
        int u = pq1.top();
        pq1.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (--inDegree1[v] == 0) pq1.push(v);
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
