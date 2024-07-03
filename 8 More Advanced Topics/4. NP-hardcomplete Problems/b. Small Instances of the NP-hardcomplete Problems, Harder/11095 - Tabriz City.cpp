#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

int V, E;
int adj[30];
int ans, mis;

void rec(int i, int covered, int used, int depth) {
    if (depth + V - i <= mis) return; // nice optimization!
    if (covered == (1 << V) - 1) {
        if (depth > mis) {
            mis = depth;
            ans = used;
        }
    } else {
        for (int j = i; j < V; j++) {
            if (!(covered & (1 << j))) {
                rec(j + 1, covered | adj[j], used | (1 << j), depth + 1);
            }
        }
    }
}

// book says min vertex cover = max independent set

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cin >> V >> E;
        mis = 0;
        ans = 0;
        memset(adj, 0, sizeof adj);
        for (int i = 0; i < V; ++i) adj[i] = 1 << i;
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u] |= (1 << v);
            adj[v] |= (1 << u);
        }
        rec(0, 0, 0,0);
        cout << "Case #" << cases << ": " << V - mis << endl;
        vector<int> anss;
        for (int i = 0; i < V; ++i) {
            if (!(ans & (1 << i))) anss.push_back(i);
        }
        for (int i = 0; i < anss.size(); ++i) {
            cout << anss[i] << (i == anss.size() - 1 ? "\n" : " ");
        }
        if (anss.size() == 0) cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
