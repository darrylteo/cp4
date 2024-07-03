#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;

vector<vector<ii>> AL;
priority_queue<iii> pq;
vi taken, p, pAns, stop, sub; // p = parent. pAns = parent for final ans. stop = must stop here (judge or end), subgraph for subset of cities
int N, t, E, J, bestDist, bestNodes; // num vertices, target, num edges, num judges

// from book code but do not process if not in subgraph
void process(int u) {
    taken[u] = 1;
    for (auto &[v, w]: AL[u])
        if (sub[v] && !taken[v]) pq.emplace(-w, -v, -u);
}

int prim(int cnt) {
    taken.assign(N, 0); // we can also mark all unused cities in subgraph as taken
    for (int i = 0; i < N; ++i)
        if (!sub[i]) taken[i] = 1;
    p.assign(N, -1);
    process(t);
    int mst_cost = 0, num_taken = 0;
    while (!pq.empty()) {
        auto [w, u, uu] = pq.top();
        pq.pop();
        w = -w, u = -u, uu = -uu;
        if (taken[u]) continue;
        mst_cost += w;
        process(u);
        ++num_taken;
        p[u] = uu;
        if (num_taken == cnt - 1) break;
    }
    return num_taken == cnt - 1 ? mst_cost : -1;
}

// picks vertices to visit (try all). id is id of next city to consider. if in stop, visit, else can visit or not
void dfs(int id) {
    if (id == N) {
        int cnt = accumulate(sub.begin(), sub.end(), 0), ans = prim(cnt);
        if (ans == -1) return;
        if (ans < bestDist || (ans == bestDist && cnt < bestNodes)) {
            bestDist = ans;
            bestNodes = cnt;
            pAns = p;
        }
        return;
    }
    sub[id] = 1;
    dfs(id + 1);
    if (!stop[id]) { // can opt to not visit this location
        sub[id] = 0;
        dfs(id + 1);
    }
}

void print(int u, int first) {
    if (first) cout << "   " << u+1;
    else cout << '-' << u+1;
    if (u == t) {
        cout << '\n';
        return;
    }
    print(pAns[u], 0);
}

// poggies. AC verdict even though the parent vector seems uncertain

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 1;
    while (cin >> N >> t >> E, N != -1) {
        t--;
        AL.assign(N, vector<ii>());
        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
        }
        cin >> J;
        stop.assign(N, 0);
        vi ppl;
        while (J--) {
            int j;
            cin >> j;
            j--;
            ppl.push_back(j);
            stop[j] = 1;
        }
        stop[t] = 1;
        bestDist = INT_MAX;
        bestNodes = N;
        sub.assign(N, 0);
        dfs(0);
        cout << "Case " << cases++ << ": distance = " << bestDist << '\n';
        for (int &j: ppl) print(j, 1);
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
