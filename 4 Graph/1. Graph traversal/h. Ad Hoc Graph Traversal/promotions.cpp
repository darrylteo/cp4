#include <bits/stdc++.h>

using namespace std;

vector<int> adj[5005], adj2[5005];
int visited[5005];

int A, B, E, P, color;

inline int dfs(int u) {
    visited[u] = color;
    int ans = 1;
    for (int v: adj[u]) {
        if (visited[v] != color) {
            ans += dfs(v);
        }
    }
    return ans;
}

inline int dfs2(int u) {
    visited[u] = color;
    int ans = 1;
    for (int v: adj2[u]) {
        if (visited[v] != color) {
            ans += dfs2(v);
        }
    }
    return ans;
}

// ref: https://github.com/morris821028/UVa/blob/master/volume130/13015%20-%20Promotions.cpp
// man... mr morris is smart

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5005; ++i) {
        adj[i].clear();
        adj2[i].clear();
    }
    memset(visited, 0, sizeof(visited));

    cin >> A >> B >> E >> P;
    for (int i = 0; i < P; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }

    int ans1 = 0, ans2 = 0, ans3 = 0;
    color = 1;
    for (int i = 0; i < E; ++i) {
        int worst, best;
        color++;
        worst = E - dfs(i); // if don't promote i, dfs(i) ppl cannot be promoted. can still promote E - dfs(i) without promoting i
        color++;
        best = dfs2(i); // you must promote dfs2(i) ppl to promote i
        if (worst < A) ans1++; // if u cannot promote A ppl, you must promote i
        if (worst < B) ans2++; // if u cannot promote B ppl, you must promote i
        if (best > B) ans3++; // you need to promote too many ppl to reach i
    }
    cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

