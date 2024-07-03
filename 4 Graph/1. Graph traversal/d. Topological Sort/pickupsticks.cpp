#include <bits/stdc++.h>

using namespace std;

int inDegree[1000005], n, m, usedCnt;
vector<int> adjList[1000005], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    usedCnt = 0;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        adjList[i].clear();
        inDegree[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        ++inDegree[v];
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        ++usedCnt;
        for (int v: adjList[u]) {
            --inDegree[v];
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (usedCnt != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



