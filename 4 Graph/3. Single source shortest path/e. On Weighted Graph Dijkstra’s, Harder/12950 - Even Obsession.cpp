#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M) {
        vector<vii> adj(N);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vi dist(N, 1e8);
        priority_queue<ii, vii, greater<ii>> pq;
        pq.emplace(0, 0);
        dist[0] = 0;
        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();
            if (front.second == N - 1) break; // early break
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;
            for (auto &[v, w] : adj[u]) {
                for (auto &[v2, w2] : adj[v]) {
                    if (dist[u] + w + w2 < dist[v2]) {
                        dist[v2] = dist[u] + w + w2;
                        pq.emplace(dist[v2], v2);
                    }
                }
            }
        }

        int ans = dist[N - 1];
        if (ans == 1e8) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
