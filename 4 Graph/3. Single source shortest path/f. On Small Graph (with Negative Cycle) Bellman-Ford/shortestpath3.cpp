#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<bool> reachable;

void dfs(int u, vector<vii> &AL) {
    reachable[u] = true;
    for (auto &[v, w]: AL[u]) {
        if (!reachable[v]) dfs(v, AL);
    }
}

// direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q, s;
    while (cin >> n >> m >> q >> s, n) {

        vector<vii> AL(n, vii());
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
        }

        // Bellman Ford's routine, basically = relax all E edges V-1 times
        vi dist(n, 1e9);
        dist[s] = 0;
        for (int i = 0; i < n - 1; ++i) {                // total O(V*E)
            bool modified = false;                       // optimization
            for (int u = 0; u < n; ++u)                  // these two loops = O(E)
                if (dist[u] != 1e9)                        // important check
                    for (auto &[v, w]: AL[u]) {             // C++17 style
                        if (dist[u] + w >= dist[v]) continue;    // not improving, skip
                        dist[v] = dist[u] + w;                   // relax operation
                        modified = true;                       // optimization
                    }
            if (!modified) break;                        // optimization
        }

        reachable.assign(n, false);
        bool hasNegativeCycle = false;
        for (int u = 0; u < n; ++u) {               // one more pass to check
            if (dist[u] != 1e9) {
                for (auto &[v, w]: AL[u]) {             // C++17 style
                    if (dist[v] > dist[u] + w) {                 // should be false
                        hasNegativeCycle = true;               // if true => -ve cycle
                        reachable[v] = true;                    // v is reachable
                    }
                }
            }
        }
        for (int u = 0; u < n; ++u) {
            if (reachable[u]) {
                dfs(u, AL);
            }
        }

        while (q--) {
            int u;
            cin >> u;
            if (dist[u] == 1e9) {
                cout << "Impossible" << endl;
            } else if (reachable[u]) {
                cout << "-Infinity" << endl;
            } else {
                cout << dist[u] << endl;
            }
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}