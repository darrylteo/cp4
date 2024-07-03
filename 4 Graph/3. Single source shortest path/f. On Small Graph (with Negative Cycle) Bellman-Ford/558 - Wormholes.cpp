#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        vector<vii> AL(V, vii());
        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
        }

        // Bellman Ford's routine, basically = relax all E edges V-1 times
        vi dist(V, 1e9);
        dist[0] = 0;
        for (int i = 0; i < V - 1; ++i) {                // total O(V*E)
            bool modified = false;                       // optimization
            for (int u = 0; u < V; ++u)                  // these two loops = O(E)
                if (dist[u] != 1e9)                        // important check
                    for (auto &[v, w]: AL[u]) {             // C++17 style
                        if (dist[u] + w >= dist[v]) continue;    // not improving, skip
                        dist[v] = dist[u] + w;                   // relax operation
                        modified = true;                       // optimization
                    }
            if (!modified) break;                        // optimization
        }

        bool hasNegativeCycle = false;
        for (int u = 0; u < V; ++u)                    // one more pass to check
            if (dist[u] != 1e9)
                for (auto &[v, w]: AL[u])                 // C++17 style
                    if (dist[v] > dist[u] + w)                 // should be false
                        hasNegativeCycle = true;               // if true => -ve cycle

        if (hasNegativeCycle) cout << "possible\n";
        else cout << "not possible\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}