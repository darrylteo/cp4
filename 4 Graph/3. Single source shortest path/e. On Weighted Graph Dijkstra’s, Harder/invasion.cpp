#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// majority of submissions are TLE
// what?? just a basic dijkstra works! weird 5.4 difficulty rating

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, A, K;
    while (cin >> N >> M >> A >> K, N) {
        vector<vii> adjList(N);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }

        vi dist(N, INT_MAX);
        priority_queue<ii, vii, greater<ii>> pq;

        while (A--) {
            int a;
            cin >> a;
            a--;
            dist[a] = 0;
            pq.push(ii(0, a));

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u]) continue;
                for (auto [v, w] : adjList[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push(ii(dist[v], v));
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < N; i++) {
                if (dist[i] >= K) ans++;
            }
            cout << ans << '\n';
        }

        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}