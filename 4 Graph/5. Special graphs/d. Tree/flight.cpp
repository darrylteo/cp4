#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, badU, badV, diameter, edgeNode;
vvi adj;
vi parent, dist;

// update diameter, edgeNode, parent, dist.
// uses badU, badV, adj.
inline void update(int start) {
    // find edge node
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int maxDist = 0;
    edgeNode = start;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if ((u == badU && v == badV) || (u == badV && v == badU)) continue; // skip bad edge
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
                if (dist[v] > maxDist) {
                    maxDist = dist[v];
                    edgeNode = v;
                }
            }
        }
    }
    // find diameter and update parent
    vi dist2(n + 1, -1);
    q.push(edgeNode);
    dist2[edgeNode] = 0;
    maxDist = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if ((u == badU && v == badV) || (u == badV && v == badU)) continue; // skip bad edge
            if (dist2[v] == -1) {
                dist2[v] = dist2[u] + 1;
                parent[v] = u;
                q.push(v);
                if (dist2[v] > maxDist) {
                    maxDist = dist2[v];
                    edgeNode = v;
                }
            }
        }
    }
    diameter = maxDist;
}

// uses diameter, edgeNode, parent
// used after update
inline int getCenter() {
    int mid = diameter / 2;
    int curr = edgeNode;
    for (int i = 0; i < mid; i++) {
        curr = parent[curr];
    }
    return curr;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // get input
    cin >> n;
    adj.assign(n + 1, vi());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // get list of badU and badV (all edges along diameter)
    parent.assign(n + 1, -1);
    dist.assign(n + 1, -1);
    badU = badV = 0; // no bad nodes
    update(1); // any start node is fine for first run since only 1 tree
    vi badNodes;
    for (int i = 0; i < diameter + 1; i++) { // + 1 because diameter is the number of edges and we want nodes
        badNodes.push_back(edgeNode);
        edgeNode = parent[edgeNode];
    }
    int initialDiameter = diameter;
    // try removing each edge along diameter and find the center of the both trees and join them together and get new diameter
    int minDiameter = INT_MAX;
    int removeU, removeV, addU, addV;
    for (int i = 0; i < badNodes.size() - 1; ++i) {
        badU = badNodes[i];
        badV = badNodes[i + 1];
        parent.assign(n + 1, -1);
        dist.assign(n + 1, -1);
        vi centers;
        for (int j = 1; j <= n; j++) {
            if (dist[j] == -1) { // this should happen twice.
                update(j);
                centers.push_back(getCenter());
            }
        }
        // temp join the 2 centers
        adj[centers[0]].push_back(centers[1]);
        adj[centers[1]].push_back(centers[0]);
        // get new diameter
        parent.assign(n + 1, -1);
        dist.assign(n + 1, -1);
        update(1); // any node is fine since only 1 tree here too
        if (diameter < minDiameter) {
            minDiameter = diameter;
            removeU = badU;
            removeV = badV;
            addU = centers[0];
            addV = centers[1];
        }
        // remove the temp join
        adj[centers[0]].pop_back();
        adj[centers[1]].pop_back();
    }
    cout << minDiameter << endl;
    cout << removeU << " " << removeV << "\n" << addU << " " << addV << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
