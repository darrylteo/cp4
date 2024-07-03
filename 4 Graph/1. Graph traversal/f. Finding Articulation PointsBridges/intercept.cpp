#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// do dijkstra to get adj list. normally dijkstra update path if new path is smaller than previous path
// in this case, update path if new path is equal also.
// tried finding articulation points but WA ...
// instead ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_4_Graph/Graph_Traversal/kattis_intercept.cpp

vi ts, visited, parents[100005];

void toposort(int u){
    visited[u] = 1;
    for (auto v: parents[u]){
        if (visited[v] == 0){
            toposort(v);
        }
    }
    ts.push_back(u);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // dijkstra here
    vector<pair<int, int>> adjDijk[N];
    ll dist[N]; // why is dist 1e9 -_-
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        adjDijk[u].emplace_back(v, w);
    }
    int src, dest;
    cin >> src >> dest;

    for (int i = 0; i < N; ++i) {
        dist[i] = 1e18;
    }
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (dist[cur.second] < cur.first) continue; // bad
        if (cur.second == dest) break;
        for (auto nxt: adjDijk[cur.second]) { // for each neighbor of cur
            if (dist[nxt.first] > cur.first + nxt.second) { // sure replace. shorter route found
                parents[nxt.first].clear(); // replace
                parents[nxt.first].push_back(cur.second); // add new route
                dist[nxt.first] = cur.first + nxt.second; // update dist
                pq.emplace(dist[nxt.first], nxt.first);
            } else if (dist[nxt.first] == cur.first + nxt.second) { // equal. add "new" route
                parents[nxt.first].push_back(cur.second); // add new route
            }
        }
    }

    // topological sort
    visited.assign(N, 0);
    toposort(dest);
    reverse(ts.begin(), ts.end());
    vector<double> flow(N, 0);
    flow[dest] = 1;

    // get flow
    for (auto u: ts){
        for (auto v: parents[u]){
            flow[v] += flow[u] / (double) parents[u].size();
        }
    }

    // print
    for (int i = 0; i < N; ++i) {
        if (abs(flow[i] - 1) < 1e-9) cout << i << " ";
    }
    cout << endl;



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



