#include <bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int,int> iiii;
typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;

// UFDS code from ch2/ownlibrary/ufds.cpp
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;                           // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }

    int numDisjointSets() { return numSets; }

    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

// maximize the minimum... so do maximum spanning tree
// then from used edges, bfs to find path from 0 to n-1
// print all the edges NOT used
// template code from book
// kinda implementation heavy for a medium qn...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Kruskal's algorithm
    int V, E;
    cin >> V >> E;
    vector<iiii> EL(E);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        EL[i] = {w, u, v, i}; // reorder as (w, u, v, id)
    }
    sort(EL.begin(), EL.end(), greater<iiii>()); // change to greater for MAXIMUM spanning tree
    // note: std::tuple has built-in comparison function

    int mst_cost = 0, num_taken = 0;
    UnionFind UF(V);
    vector<iiii> used_edges; // last idx is id
    for (int i = 0; i < E; ++i) {
        auto [w, u, v, x] = EL[i];
        if (UF.isSameSet(u, v)) continue;
        mst_cost += w;
        UF.unionSet(u, v);
        ++num_taken;
        used_edges.emplace_back(u, v, w, i);
        if (num_taken == V - 1) break;
    }

    // get path from node 0 to n-1
    vector<vector<pair<int,int>>> AL(V); // (to node, edge id)
    for (auto [u, v, w, id] : used_edges) {
        AL[u].emplace_back(v, id);
        AL[v].emplace_back(u, id);
    }
    vector<int> parent(V, -1);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, id] : AL[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            q.push(v);
        }
    }
    vector<int> path;
    for (int u = V - 1; u != -1; u = parent[u]) path.push_back(u);
    reverse(path.begin(), path.end());
    // all edges that are touching vertices in path, but not actual path, we block
    vector<bool> blocked(E, false);
    // first node
    int u = path[0];
    int v = path[1];
    for (int j = 0; j < E; ++j) {
        auto [w, uu, vv, id] = EL[j];
        if ((uu == u && vv != v) || (vv == u && uu != v)) {
            blocked[id] = true;
        }
    }
    for (int i = 1; i < (int) path.size() - 1; ++i) {
        int u = path[i], v = path[i + 1], v1 = path[i - 1];
        for (int j = 0; j < E; ++j) {
            auto [w, uu, vv, id] = EL[j];
            if ((uu == u && vv != v && vv != v1) || (vv == u && uu != v && uu != v1)) {
                blocked[id] = true;
            }
        }
    }
    // last node
    u = path[path.size() - 1];
    v = path[path.size() - 2];
    for (int j = 0; j < E; ++j) {
        auto [w, uu, vv, id] = EL[j];
        if ((uu == u && vv != v) || (vv == u && uu != v)) {
            blocked[id] = true;
        }
    }
    // print all blocked
    for (int i = 0; i < E; ++i) {
        if (blocked[i]) cout << i << ' ';
    }
    // if none blocked print none
    if (count(blocked.begin(), blocked.end(), true) == 0) cout << "none";


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}