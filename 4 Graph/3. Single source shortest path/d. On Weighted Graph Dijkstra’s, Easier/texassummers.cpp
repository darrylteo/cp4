#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int parent[2505];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vii points(n + 2);
    // get points
    int x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        points[i] = {x, y};
    }
    cin >> x >> y;
    points[0] = {x, y};
    cin >> x >> y;
    points[n + 1] = {x, y};
    // now n is total points. go from 0 to n-1
    n += 2;
    // get AL
    vector<vii> AL(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            AL[i].emplace_back(j, dx * dx + dy * dy);
            AL[j].emplace_back(i, dx * dx + dy * dy);
        }
    }

    //  Dijkstra's algorithm
    vi dist(n, 1e9);
    dist[0] = 0;
    memset(parent, -1, sizeof parent);

    set<ii> pq;
    for (int i = 0; i < n; i++) pq.emplace(dist[i], i); // sort by (d, u)

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto &[v, w] : AL[u]) {
            if (dist[u] + w < dist[v]) {
                pq.erase({dist[v], v});            // remove the old pair
                dist[v] = dist[u] + w;              // u is v's predecessor
                pq.emplace(dist[v], v);            // add the new pair
                parent[v] = u;
            }
        }
    }

    vi ans;
    int fin = n - 1;
    while (fin != -1) {
        ans.push_back(fin);
        fin = parent[fin];
    }
    if (ans.size() == 2) {
        cout << "-\n";
    } else {
        reverse(ans.begin(), ans.end());
        for (int i = 1; i < ans.size() - 1; ++i) {
            cout << ans[i] - 1 << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}