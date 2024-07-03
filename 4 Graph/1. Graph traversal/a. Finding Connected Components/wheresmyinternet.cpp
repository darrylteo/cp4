#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1, VISITED = -2
};

vi AL[200001];
int dfsNum[200001];

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

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    memset(dfsNum, UNVISITED, sizeof(dfsNum));
    dfs(1);
    int flag = 0;
    for (int i = 2; i <= N; i++) {
        if (dfsNum[i] == UNVISITED) {
            cout << i << endl;
            flag = 1;
        }
    }
    if (!flag) {
        cout << "Connected" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}