#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// need learn lowest common ancestor else TLE
// code template from https://noiref.codecla.ws/ds/#sparse
// just like UFDS/fenwick/segment tree, i will just copy paste the algorithm and use it as a subroutine

/* Pre-computation using DFS */
const int MAXN = 200005;
const int LOGN = 21;
int p[LOGN+1][MAXN], h[MAXN];   //h: number of edges from root
long long d[MAXN];     //dist: sum of edge weight from root
vector<pair<int, int> > adjList[MAXN];   //node, weight
bitset<MAXN> visited;
void dfs(int x) {
    if (visited[x]) return;
    visited[x] = 1;
    for (int k = 0; k < LOGN; ++k) {
        if (p[k][x] == -1) break;
        p[k+1][x] = p[k][p[k][x]];
    }
    for (auto it:adjList[x]) {
        if (visited[it.first]) continue;
        p[0][it.first] = x;
        d[it.first] = d[x] + it.second;
        h[it.first] = h[x] + 1;
        dfs(it.first);
    }
}

/* Query */
int lca(int a, int b) { //h[a] < h[b]
    if (h[a] > h[b]) swap(a, b);
    /* advance b by h[b] - h[a] parents */
    for (int k = 0, d = h[b] - h[a]; k < LOGN; ++k) {
        if (d & (1<<k))  b = p[k][b];
    }
    if (a == b) return a;
    assert(h[a] == h[b]); //same height
    /* to be continued */
    for (int k = LOGN-1; k >= 0; --k) {
        if (p[k][a] != p[k][b])
            a = p[k][a], b = p[k][b];
    }
    assert(p[0][a] == p[0][b]);        //same immediate parent
    return p[0][a];
}

long long dist(int a, int b) {
    int c = lca(a, b);
    return d[a] + d[b] - 2 * d[c];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    n++;
    for (int i = 0; i < n - 2; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].emplace_back(v, 1);
        adjList[v].emplace_back(u, 1);
    }
    dfs(1);
    long long ans = 0;
    for (int i = 1; i < n / 2 + 1; ++i) {
        for (int j = 2; j * i < n; ++j) {
            int node = j * i;
            ans += dist(i, node) + 1;
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

