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
    for (int caseNo = 1; caseNo <= cases; ++caseNo) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        vector<vii> adjList(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].emplace_back(v, w);
            adjList[v].emplace_back(u, w);
        }

        vi dist(n, INT_MAX);
        priority_queue<ii, vii, greater<ii>> pq;
        pq.emplace(0, S);
        dist[S] = 0;
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
        cout << "Case #" << caseNo << ": ";
        if (dist[T] == INT_MAX) cout << "unreachable" << endl;
        else cout << dist[T] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}