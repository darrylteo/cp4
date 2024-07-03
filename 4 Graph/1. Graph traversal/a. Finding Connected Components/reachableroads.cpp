#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1, VISITED = -2
};

vi AL[1001];
int dfsNum[1001];

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
        int m, r;
        cin >> m >> r;
        for (int i = 0; i < m; ++i) {
            AL[i].clear();
        }
        while (r--) {
            int u, v;
            cin >> u >> v;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }
        memset(dfsNum, UNVISITED, sizeof dfsNum);
        int CC = 0;
        for (int i = 0; i < m; ++i) {
            if (dfsNum[i] == UNVISITED) {
                dfs(i);
                CC++;
            }
        }
        cout << CC - 1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}