#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

int n, m;
vii adj[2000];

// let each floor contain nodes from 1 to m
// for 1st example, when m == 2, for 1st line input 1 2. 1 is from node 0 to node 2+0. 2 is from node 0 to node 2+1
// for 2nd line input 3 4. 3 is from node 1 to node 2+0. 4 is from node 1 to node 2+1
// node 0-1 has 0 dist. we want to go to any node 4-5. (3rd floor)
// multisource dijkstra (super source node 1999)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        cout << s << '\n';
        cin >> n >> m;
        for (auto &i: adj) i.clear();
        for (int i = 0; i < m * (n - 1); ++i) {
            for (int j = 0; j < m; ++j) {
                int w;
                cin >> w;
                int currFloor = i / m;
                int nextFloor = currFloor + 1;
                adj[i].emplace_back(m * nextFloor + j, w);
            }
        }
        // super source
        for (int i = 0; i < m; ++i) {
            adj[1999].emplace_back(i, 0);
        }
        // dijkstra
        vi dist(2000, 1e9);
        priority_queue<ii, vii, greater<ii>> pq;
        pq.push({0, 1999});
        dist[1999] = 0;
        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();
            int d = front.first;
            int u = front.second;
            if (d > dist[u]) continue;
            for (auto &j: adj[u]) {
                int v = j.first;
                int w = j.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 1e9;
        for (int j = m * (n - 1); j < m * n; ++j) { // for each (n-1)th floor node
            ans = min(ans, dist[j]);
        }
        cout << ans + 2 * (n - 1) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}