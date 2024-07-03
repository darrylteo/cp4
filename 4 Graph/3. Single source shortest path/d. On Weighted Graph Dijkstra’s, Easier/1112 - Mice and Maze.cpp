#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        int N, E, T, M;
        cin >> N >> E >> T >> M;
        vector<vii> adjList(N + 1);
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].emplace_back(v, w);
        }

        // gotta do dijkstra for each starting cell
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            vi dist(N + 1, INT_MAX);
            priority_queue<ii, vii, greater<ii>> pq;
            pq.emplace(0, i);
            dist[i] = 0;
            while (!pq.empty()) {
                ii front = pq.top();
                pq.pop();
                int d = front.first, u = front.second;
                if (d > dist[u]) continue;
                for (auto &v: adjList[u]) {
                    if (dist[u] + v.second < dist[v.first]) {
                        dist[v.first] = dist[u] + v.second;
                        pq.emplace(dist[v.first], v.first);
                    }
                }
            }
            if (dist[E] <= T) ++ans;
        }
        cout << ans << endl;
        if (cases) cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}