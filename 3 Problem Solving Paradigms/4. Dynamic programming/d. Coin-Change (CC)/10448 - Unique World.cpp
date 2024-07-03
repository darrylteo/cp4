#include <bits/stdc++.h>

using namespace std;

// ref: https://github.com/evandrix/UVa/blob/master/10448.cpp
// important note: All the houses are connected by roads in such a way so that there is exactly one (unique !!) path from one house to another one.

const int MAXN = 55;
const int MAXC = 110000 / 2;
const int INF = 1e5;

struct edge {
    int target, cost;
};

vector<edge> edges[MAXN]; // another way to define vector of vectors
bool vis[MAXN];

bool findPath(int start, vector<int> &cost, int &ans, int end) {
    if (start == end) return true;
    vis[start] = true; // visited
    for (int i = 0; i < edges[start].size(); i++) {
        int next = edges[start][i].target;
        if (!vis[next]) { // don't visit a house twice. there is a single unique path
            if (findPath(next, cost, ans, end)) {
                cost.push_back(edges[start][i].cost);
                ans -= edges[start][i].cost;
                return true;
            }
        }
    }
    return false;
}

int dp[MAXC];
int solve(int n, int start, int end, int ans) {
    for (int i = 0; i < MAXC; i++) dp[i] = INF; // memset only works for 0 and -1 .
    memset(vis, false, sizeof(vis));
    vector<int> cost;
    if (start == end) return INF; // i dun think he should walk to his own house?
    if (!findPath(start, cost, ans, end)) return INF;
    if (ans < 0 || ans % 2 == 1) return INF; // after walking direct path, can back and forth on any (non-last) path
    if (ans == 0) return cost.size();
    cost.erase(cost.begin()); // last path to target cannot walk twice
    if (cost.size() == 0) return INF; // no path to target (since ans > 0 and no more path to walk)
    ans /= 2; // back and forth
    dp[0] = 0; // bottom up approach
    for (int i = 1; i <= ans; i++) {
        for (int dist: cost) {
            if (i - dist >= 0) {
                dp[i] = min(dp[i], dp[i - dist] + 1);
            }
        }
    }
    if (dp[ans] == INF) return INF;
    // extra backNforths + direct path + last path
    return dp[ans] * 2 + cost.size() + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < MAXN; i++) edges[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            edges[u].push_back({v, c});
            edges[v].push_back({u, c});
        }
        int q;
        cin >> q;
        while (q--) {
            int start, end, ans;
            cin >> start >> end >> ans;
            int res = solve(n, start, end, ans);
            if (res == INF) cout << "No" << endl;
            else cout << "Yes " << res << endl;
        }
        if (tc) cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
