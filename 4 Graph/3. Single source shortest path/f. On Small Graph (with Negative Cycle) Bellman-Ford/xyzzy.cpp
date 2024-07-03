#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// person want to take the most positive path so just put (-) and find min path

vi canReach;

void dfs(int u, vector<vii> &AL) {
    canReach[u] = 1;
    for (auto &[v, w]: AL[u]) {
        if (canReach[v]) continue; // already checked
        dfs(v, AL);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V;
    while (cin >> V) {
        if (V == -1) break;
        vector<vii> AL(V, vii());
        vector<vi> tmpAL(V);
        vi roomValue(V);
        for (int i = 0; i < V; ++i) {
            int w, E;
            cin >> w >> E;
            roomValue[i] = w;
            for (int j = 0; j < E; ++j) {
                int v;
                cin >> v;
                v--;
                tmpAL[i].push_back(v);
            }
        }
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < tmpAL[i].size(); ++j) {
                int v = tmpAL[i][j];
                AL[i].emplace_back(v, -roomValue[v]);
            }
        }

        // Bellman Ford's routine, basically = relax all E edges V-1 times
        vi dist(V, 1e9);
        dist[0] = -100;
        for (int i = 0; i < V - 1; ++i) {                // total O(V*E)
            bool modified = false;                       // optimization
            for (int u = 0; u < V; ++u)                  // these two loops = O(E)
                if (dist[u] < 0)                        // important check
                    for (auto &[v, w]: AL[u]) {             // C++17 style
                        if (dist[u] + w >= dist[v]) continue;    // not improving, skip
                        dist[v] = dist[u] + w;                   // relax operation
                        modified = true;                       // optimization
                    }
            if (!modified) break;                        // optimization
        }

        vi tmpDist = dist;
        // Run the algorithm a second time and see what gets "updated"
        for (int u = 0; u < V; ++u) {
            if (tmpDist[u] < 0) {
                for (auto &[v, w]: AL[u]) {
                    if (tmpDist[u] + w >= tmpDist[v]) continue;
                    tmpDist[v] = tmpDist[u] + w;
                }
            }
        }
        vi updatedNodes;
        for (int i = 0; i < V; ++i) {
            if (tmpDist[i] != dist[i]) {
                updatedNodes.push_back(i);
            }
        }
        // run bfs to find all nodes that can reach the cycle nodes
        canReach.assign(V, 0);
        for (int i = 0; i < updatedNodes.size(); ++i) {
            if (canReach[updatedNodes[i]]) continue; // already checked
            dfs(updatedNodes[i], AL);
        }

        if (canReach[V - 1] || dist[V - 1] <= 0) cout << "winnable\n";
        else cout << "hopeless\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}