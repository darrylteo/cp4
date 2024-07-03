#include <bits/stdc++.h>

using namespace std;

int mark[1000], stk[1000], stkIdx, N;
vector<vector<int>> adj;

// this dfs checks if any husband left implies husband right. or vice versa on 2nd run of dfs(i^1)
int dfs(int u) {
    if (mark[u ^ 1]) return 0;
    if (mark[u]) return 1;
    mark[u] = 1;
    stk[stkIdx++] = u; // just mark "stack". many chinese sites use this for tarjan algorithm
    for (int v: adj[u]) {
        if (!dfs(v)) return 0;
    }
    return 1;
}

int solvable() {
    memset(mark, 0, sizeof mark);
    for (int i = 0; i < N; i += 2) {
        if (!mark[i] && !mark[i + 1]) {
            stkIdx = 0;
            if (!dfs(i)) {
                // reset anything done by this dfs(i).
                // we leave marks either by i or i^1 before continuing to next iteration
                while (stkIdx) mark[stk[--stkIdx]] = 0;
                if (!dfs(i ^ 1)) return 0;
            }
        }
    }
    return 1;
}

// assume wife always left. without loss of generality
// ref: https://github.com/morris821028/UVa/blob/master/volume112/11294%20-%20Wedding.cpp
// morris solution very elegant. feels tailored to this qn, not a regular SCC.
// was unable to print solution using tarjan...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        N = 2 * n;
        // 0 means 0h sit left, 1 means 0h sit right, 2 means 1h sit left, 3 means 1h sit right, and so on
        adj.assign(N, vector<int>());
        // we reduce vars to just where husband sit since wife MUST sit opposite
        for (int i = 0; i < m; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            int u = 2 * stoi(s1.substr(0, s1.size() - 1)) + (s1[s1.size() - 1] != 'h');
            int v = 2 * stoi(s2.substr(0, s2.size() - 1)) + (s2[s2.size() - 1] != 'h');
            // if person u sit on right, then person v must sit on left.
            // we only care about the implication when u sit on right since if u sit left,
            // v can sit left or right is ok. same argument for v
            adj[u ^ 1].push_back(v);
            adj[v ^ 1].push_back(u);
        }
        adj[0].push_back(1); // 0h sit left
        if (!solvable()) {
            cout << "bad luck\n";
        } else {
            for (int i = 2; i < N; i += 2) {
                if (mark[i]) cout << i / 2 << "h" << (i < N - 2 ? " " : "\n");
                else cout << i / 2 << "w" << (i < N - 2 ? " " : "\n");
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
