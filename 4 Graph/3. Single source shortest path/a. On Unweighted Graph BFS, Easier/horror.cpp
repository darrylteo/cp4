#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but shortcuts are useful in competitive programming


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, H, L;
    cin >> N >> H >> L;
    vector<vi> adj(N);
    vi dist(N, 1e9);
    queue<int> q;
    for (int i = 0; i < H; ++i) {
        int a;
        cin >> a;
        q.push(a);
        dist[a] = 0;
    }
    for (int i = 0; i < L; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == 1e9) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int max_dist = 0;
    int max_node = 0;
    for (int i = 0; i < N; ++i) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            max_node = i;
        }
    }
    cout << max_node << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}