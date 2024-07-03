#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;

// try using SPFA

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, cases = 1;
    while (cin >> n) {
        vector<int> nodes(n);
        for (int i = 0; i < n; i++) cin >> nodes[i];
        cin >> m;
        vector<vii> AL(n, vii());
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            AL[u].emplace_back(v, (nodes[v] - nodes[u]) * (nodes[v] - nodes[u]) * (nodes[v] - nodes[u]));
        }

        // weird qn allow n == 0
        if (n == 0) {
            cout << "Set #" << cases++ << endl;
            int Q;
            cin >> Q;
            while (Q--) cout << "?" << endl;
            continue;
        }

        // SPFA from source S
        vi dist(n, INF), in_queue(n, 0), visits(n, 0);
        dist[0] = 0;                  // INF = 1e9 here
        queue<int> q;
        q.push(0);                       // like BFS queue
        in_queue[0] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = 0; // pop from queue

            visits[u]++;                                   // count the number of visits
            if (visits[u] > n) continue; // not == n so can do 1 last propagation to track those in negative cycle

            for (auto &[v, w]: AL[u]) {                 // C++17 style
                if (dist[u] + w >= dist[v]) continue;        // not improving, skip
                dist[v] = dist[u] + w;                       // relax operation
                if (!in_queue[v]) {                        // add to the queue
                    q.push(v);                               // only if v is not
                    in_queue[v] = 1;                         // already in the queue
                }
            }
        }

        int Q;
        cin >> Q;
        cout << "Set #" << cases++ << endl;
        while (Q--) {
            int x;
            cin >> x;
            x--;
            if (dist[x] < 3 || dist[x] > 1e6 || visits[x] >= n) cout << "?" << endl;
            else cout << dist[x] << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}