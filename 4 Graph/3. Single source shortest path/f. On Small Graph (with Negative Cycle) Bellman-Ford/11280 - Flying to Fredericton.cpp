#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;

// modify dijkstra to check for shortest path from a to b, for all number of allowed connections
// no need bellman since no negative cycles
// slow...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Scenario #" << cases << "\n";
        int n, m;
        map<string, int> mp;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            mp[s] = i;
        }
        cin >> m;
        vector<vii> adjList(n, vii());
        for (int i = 0; i < m; ++i) {
            string a, b;
            int w;
            cin >> a >> b >> w;
            adjList[mp[a]].emplace_back(mp[b], w);
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        dist[0][0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u][n - 1]) continue;
            for (auto &v: adjList[u]) {
                for (int i = 0; i < n - 1; ++i) {
                    if (dist[u][i] + v.second < dist[v.first][i + 1]) {
                        dist[v.first][i + 1] = dist[u][i] + v.second;
                        pq.push({dist[v.first][i + 1], v.first});
                    }
                }
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int k;
            cin >> k;
            k++; // 0 layover is 1 edge
            k = min(k, n - 1); // important... else undefined behavior since we cannot have more than n-1 legs in path of max n nodes
            int minCost = INF;
            for (int i = 0; i <= k; ++i) {
                minCost = min(minCost, dist[n - 1][i]);
            }
            if (minCost == INF) cout << "No satisfactory flights\n";
            else cout << "Total cost of flight(s) is $" << minCost << "\n";
        }
        if (cases != T) cout << "\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}