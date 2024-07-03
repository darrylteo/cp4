#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1, VISITED = -2
};

vii AL[505];
int dfsNum[505], cnt, maxPPA;

void dfs(int u) {
    dfsNum[u] = VISITED;
    for (auto v: AL[u]) {
        if (dfsNum[v.first] == UNVISITED && v.second == maxPPA) {
            cnt++;
            dfs(v.first);
        }
    }
}

// the trick is, we can only build roads that are maximum PPA. if add a lower PPA, better off building just 1 road
// we count maximum possible number of cities in such a province NOT roads... oops

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, m;
    while(cin >> n >> m, n) {
        for (int i = 1; i <= n; i++) {
            AL[i].clear();
            dfsNum[i] = UNVISITED;
        }

        maxPPA = INT_MIN;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].push_back(ii(v, w));
            AL[v].push_back(ii(u, w));
            maxPPA = max(maxPPA, w);
        }

        int bestCnt = 0;
        for (int i = 1; i <= n; i++) {
            if (dfsNum[i] == UNVISITED) {
                cnt = 0;
                dfs(i);
                bestCnt = max(bestCnt, cnt);
            }
        }

        cout << bestCnt + 1 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

