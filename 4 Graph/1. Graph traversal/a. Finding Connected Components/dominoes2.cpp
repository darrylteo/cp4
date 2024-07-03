#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1, VISITED = -2
};

vi AL[10001];
int dfsNum[10001];

void dfs(int u) {
    dfsNum[u] = VISITED;
    for (int v: AL[u]) {
        if (dfsNum[v] == UNVISITED) {
            dfs(v);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;
        for (int i = 1; i <= n; i++) {
            AL[i].clear();
        }
        while (m--) {
            int u, v;
            cin >> u >> v;
            AL[u].push_back(v);
        }
        memset(dfsNum, UNVISITED, sizeof(dfsNum));
        while (l--) {
            int u;
            cin >> u;
            if (dfsNum[u] == UNVISITED) {
                dfs(u);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dfsNum[i] == VISITED) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}