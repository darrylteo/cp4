#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// give up too hard after 2-3h. dijkstra using PQ can get up to case 13/25
// copy from ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_4_Graph/Special_Graphs/kattis_246greaaat.cpp

int e, dest, u, v, temp_d, w, delta, INF = (int) 1e8;
vector<tuple<int, int>> cheers; // d, weight, note that pairs are faster than tuples
vector<int> dist, dist_to_n,parent;
vector<queue<int>> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> e >> dest;
    cheers.reserve(e+1);
    cheers.emplace_back(1, 1);
    int min_cheer = 0;
    for (int i = 0; i < e; i++) {
        cin >> v >> w;
        if (v == 0){ // prevent self loops
            w = INF;
        }
        cheers.emplace_back(v, w);
        min_cheer = min(min_cheer, v);
    }
    e++; // account for first cheer
    int max_node = dest - min_cheer;
    dist.assign(max_node+ 9, INF);
    dist_to_n.assign(max_node + 9, INF);
    parent.assign(max_node + 9, -1);
    q.assign(dest+9, queue<int>());

    // Dijkstra using modified "priority queue"
    dist[0] = 0;
    parent[0] = -1;
    q[0].emplace(0);
    int meet_at = 0, total_dist = dest + 1 ;
    // dest +1 ensures that parent array is properly updated for edge cases
    for (int d=0;d<=dest; d += (q[d].empty())){
        if (q[d].empty())
            continue;

        u = q[d].front();
        q[d].pop();

        if (dist[u] >= total_dist || u == dest)break;
        if (d > dist[u])continue; // inferior pair

        // Meet in the middle stuff
        if (dest > u)
            dist_to_n[dest - u] = dist[u];
        if (dist_to_n[u] != INF){
            if (dist[u] + dist_to_n[u] < total_dist){
                meet_at = u;
                total_dist = dist[u] + dist_to_n[u];
            }
            continue;
        }
        for (int i=0; i < e; i++) {
            auto &[delta, w] = cheers[i];
            v = delta + u;
            if (v <= 0 || v > max_node)continue;
            temp_d = dist[u] + w;
            if (temp_d >= dist[v])
                continue;  // relaxing through this node doesn't help

            if (temp_d > total_dist)continue; // out of bounds (ie will never go there)

            dist[v] = temp_d;

            parent[v] = i;
            q[temp_d].emplace(v);
        }
    }

    vector<int> path;
    int cur_node = meet_at;
    while (cur_node != 0) {
        path.emplace_back(parent[cur_node]);
        auto [d, w] = cheers[parent[cur_node]];
        cur_node = cur_node - d;
    }
    cur_node = dest-meet_at;
    while (cur_node != 0) {
        path.emplace_back(parent[cur_node]);
        auto [d, w] = cheers[parent[cur_node]];
        cur_node = cur_node - d;
    }

    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] + 1 << " ";
    }
    cout << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}