#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

// min time is travel 1-9 and whenever get to branch, go to end and come back
//     1
//     |
//     2
//     |
//     3 - 4
//     |
//     5 - 6 - 7
//     |
//     8
//     |
//     9
//     |
//     10

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi adj[n + 1];
        for (int i = 1; i <= n; ++i){
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j){
                int x;
                cin >> x;
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        // find the furthest node from any node (we just use node 1)
        vi dist(n + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int v : adj[u]){
                if (dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int max_dist = 0;
        int max_node = 1;
        for (int i = 1; i <= n; ++i){
            if (dist[i] > max_dist){
                max_dist = dist[i];
                max_node = i;
            }
        }
        // now we can find diameter of tree
        dist.assign(n + 1, -1);
        q.push(max_node);
        dist[max_node] = 0;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int v : adj[u]){
                if (dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        max_dist = 0;
        for (int i = 1; i <= n; ++i){
            max_dist = max(max_dist, dist[i]);
        }
        int remaining = n - 1 - max_dist; // tree with n nodes has n - 1 edges
        cout << max_dist + remaining * 2 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
