#include <bits/stdc++.h>

using namespace std;

const int MAXNT = 32767; // just random guess max possible number of cities
vector<int> route[MAXNT]; // route of each ticket
int cost[MAXNT]; // cost of each ticket
int NT; // num tickets
struct Edge { // to, weight, ticket number
    int to, w, label;
    Edge(int to, int w, int label) : to(to), w(w), label(label) {}
};
vector<Edge> g[MAXNT]; // adjacency list of graph
map<pair<int, int>, int> mp; // map of (num legs completed in trip, curr node) to edge label
int getId(pair<int, int> p) { // get id of edge (auto increment)
    if (mp.find(p) == mp.end()) {
        mp[p] = (int) mp.size();
    }
    return mp[p];
}
pair<int, int> dist[MAXNT]; // (cost, num tickets used) to reach city i
int pre[MAXNT][2]; // (prev city, prev ticket label) to reach city i. predecessor info.
int inq[MAXNT]; // in queue
void spfa(int st) { // shortest path faster algorithm standard
    memset(inq, 0, sizeof(inq));
    memset(dist, 0x3f, sizeof(dist));
    memset(pre, -1, sizeof(pre));
    int u, v;
    queue<int> q;
    dist[st] = {0, 0};
    q.push(st);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        inq[u] = 0;
        for (Edge e : g[u]) {
            v = e.to;
            // check if lower cost first, then check if same cost but fewer tickets used
            if (dist[v] > make_pair(dist[u].first + e.w, dist[u].second + 1)) {
                dist[v] = {dist[u].first + e.w, dist[u].second + 1};
                pre[v][0] = u;
                pre[v][1] = e.label;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
void solve(int N, const int A[]) {
    for (auto & i : g) {
        i.clear();
    }
    mp.clear();

    for (int i = 0; i < N; ++i) { // for each leg in flight
        for (int j = 0; j < NT; j++) { // for each ticket
            int st = i, ed = i;
            for (int k = 0; k < route[j].size(); ++k) {
                if (ed+1 < N && route[j][k] == A[ed+1]) {
                    ed++;
                }
                int u = getId({st, route[j][0]}); // recall can only start from first city in ticket
                int v = getId({ed, route[j][k]}); // from start to halfway (a trick to skip legs in itinerary)
                g[u].emplace_back(v, cost[j], j);
                if (ed == N) break;
            }
        }
    }

    // ed is (last leg cnt, last node).. this is most important part of algorithm
    // rather than only going from 1 city to another, we go from 1 leg of itinerary to another too
    // lots of extra nodes but it's necessary
    int st = getId({0, A[0]}), ed = getId({N-1, A[N-1]}); 
    spfa(st);

    vector<int> ans;
    for (int i = ed; i != -1; i = pre[i][0]) {
        if (pre[i][1] != -1) {
            ans.push_back(pre[i][1]);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "Cost = " << dist[ed].first << endl;
    cout << "  Tickets used:";
    for (int i: ans) cout << " " << i+1;
    cout << endl;
}

// hard... tried dijkstra 1 city at a time but it's wrong.
// ref: https://morris821028.github.io/2015/04/20/uva-1048/
// feels like 3d dijkstra

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q, cases = 0;
    int A[MAXNT];
    while (cin >> NT, NT) {
        for (int i = 0; i < NT; ++i) {
            int m, x;
            route[i].clear();
            cin >> cost[i] >> m;
            for (int j = 0; j < m; ++j) {
                cin >> x;
                route[i].push_back(x);
            }
        }
        cin >> Q;
        ++cases;
        for (int i = 0; i < Q; ++i) {
            cin >> N;
            for (int j = 0; j < N; ++j) {
                cin >> A[j];
            }
            cout << "Case " << cases << ", Trip " << i+1 << ": ";
            solve(N, A);
        }
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


