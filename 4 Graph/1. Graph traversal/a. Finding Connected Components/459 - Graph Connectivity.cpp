#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1, VISITED = -2
};

vi AL[30];
int dfsNum[30];

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
        string s;
        cin >> s;
        int m = s[0] - 'A' + 1;
        for (int i = 0; i < m; ++i) {
            AL[i].clear();
        }
        cin.ignore();
        string buf;
        while (getline(cin, buf)) {
            if (buf.empty()) break;
            int u = buf[0] - 'A';
            int v = buf[1] - 'A';
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
        cout << CC << '\n';
        if (T) cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}