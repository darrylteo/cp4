#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

vll fib;

void generateFibonacci(ll n) {
    ll a = 0, b = 1;
    while (b <= n) {
        fib.push_back(b);
        ll c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    generateFibonacci(1e18);
    int n, m;
    cin >> n >> m;
    vi adj[n + 1], inDegree(n + 1, 0), badNodes(n + 1, 0), hasOne(n + 1, 0);
    vll heights(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i + 1];
        if (find(fib.begin(), fib.end(), heights[i + 1]) == fib.end()) {
            badNodes[i + 1] = 1;
        }
    }

    // add only valid edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // handle non prime
        if (badNodes[u] || badNodes[v]) continue;
        // handle 1s
        if (heights[u] == 1 && heights[v] == 1) {
            hasOne[u] = 1;
            hasOne[v] = 1;
        } else if (heights[u] == 1 && heights[v] == 2) {
            adj[u].push_back(v);
            inDegree[v]++;
        } else if (heights[u] == 2 && heights[v] == 1) {
            adj[v].push_back(u);
            inDegree[u]++;
        } else {
            int uPos = lower_bound(fib.begin(), fib.end(), heights[u]) - fib.begin();
            int next = uPos + 1;
            int prev = uPos - 1;
            if (prev > 0 && fib[prev] == heights[v]) {
                adj[v].push_back(u);
                inDegree[u]++;
            } else if (next < fib.size() && fib[next] == heights[v]) {
                adj[u].push_back(v);
                inDegree[v]++;
            }
        }
    }
    // process all nodes with inDegree == 0 and find longest path
    queue<int> q;
    vi dist(n + 1, 0);
    int maxDist = 0;
    for (int i = 1; i <= n; ++i) {
        if (!badNodes[i] && inDegree[i] == 0) {
            q.push(i);
            if (hasOne[i]) dist[i] = 2;
            else dist[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            dist[v] = max(dist[v], dist[u] + 1);
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    maxDist = max(maxDist, *max_element(dist.begin(), dist.end()));
    cout << maxDist << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}