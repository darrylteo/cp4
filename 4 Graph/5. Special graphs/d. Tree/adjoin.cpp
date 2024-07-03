#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vi dist(n, -1), dist2(n, -1), parent(n, -1); // dist find end node. dist2 find diameter and parent
    vii trees; // store diameter, center node idx
    vector<vi> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // get diameter and center node of each tree
    for (int i = 0; i < n; i++) {
        if (dist[i] == -1) { // a new tree
            // find "corner" node
            queue<int> q;
            q.push(i);
            dist[i] = 0;
            int maxDist = 0, edgeNode = -1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        if (dist[v] > maxDist) {
                            maxDist = dist[v];
                            edgeNode = v;
                        }
                    }
                }
            }
            // single node can skip
            if (maxDist == 0) {
                trees.emplace_back(0, i);
                continue;
            }
            // find diameter of current tree
            q.push(edgeNode);
            dist2[edgeNode] = 0;
            int maxDist2 = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: adj[u]) {
                    if (dist2[v] == -1) {
                        dist2[v] = dist2[u] + 1;
                        parent[v] = u;
                        q.push(v);
                        if (dist2[v] > maxDist2) {
                            maxDist2 = dist2[v];
                            edgeNode = v;
                        }
                    }
                }
            }
            // find center node and update trees
            int centerNode = edgeNode;
            for (int j = 0; j < maxDist2 / 2; j++) {
                centerNode = parent[centerNode];
            }
            trees.emplace_back(maxDist2, centerNode);
        }
    }
    // stick all center nodes to the center node of the tree with largest diameter
    sort(trees.begin(), trees.end());
    int center = trees.back().second;
    for (int j = 0; j < trees.size() - 1; ++j) {
        int u = trees[j].second;
        adj[u].push_back(center);
        adj[center].push_back(u);
    }
    // reset and find diameter
    fill(dist.begin(), dist.end(), -1);
    fill(dist2.begin(), dist2.end(), -1);
    queue<int> q;
    q.push(0); // start from any node
    dist[0] = 0;
    int maxDist = 0, endNode = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > maxDist) {
                    maxDist = dist[v];
                    endNode = v;
                }
            }
        }
    }
    if (endNode == -1) { // else runtime error if 1 computer 0 link
        cout << 0 << endl;
        return 0;
    }
    // find diameter of the tree
    q.push(endNode);
    dist2[endNode] = 0;
    maxDist = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (dist2[v] == -1) {
                dist2[v] = dist2[u] + 1;
                q.push(v);
                if (dist2[v] > maxDist) {
                    maxDist = dist2[v];
                    endNode = v;
                }
            }
        }
    }
    cout << maxDist << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
