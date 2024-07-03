#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
int sz;

void dfs(int u) {
    vis[u] = true;
    sz++;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

// first sample input he strike junction 2, and we add a path from 1-4

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // try all critical junctions
    int worstIdx = -1, worstCnt = -1;
    vector<int> worstSizes;
    for (int i = 0; i <= n; i++) {
        if (adj[i].size() == 1) continue; // leaf cannot be critical
        vector<int> sizes;
        vis.assign(n + 1, false);
        vis[i] = true; // strike the junction
        for (int j = 0; j <= n; j++) {
            if (!vis[j]) {
                sz = 0;
                dfs(j);
                sizes.push_back(sz);
            }
        }
        // get cnt disconnected components. easier to see when draw 1st sample input
        int cnt = 0;
        for (int j = 0; j < sizes.size(); j++) {
            for (int k = j + 1; k < sizes.size(); k++) {
                cnt += sizes[j] * sizes[k];
            }
        }
        if (cnt > worstCnt) {
            worstCnt = cnt;
            worstIdx = i;
            worstSizes = sizes;
        }
    }

    cout << worstCnt << ' ';

    // connect largest and second largest sz
    int largest = -1, largestIdx = -1;
    for (int i = 0; i < worstSizes.size(); i++) {
        if (worstSizes[i] > largest) {
            largest = worstSizes[i];
            largestIdx = i;
        }
    }
    worstSizes.erase(worstSizes.begin() + largestIdx);
    int largest2 = -1, largestIdx2 = -1;
    for (int i = 0; i < worstSizes.size(); i++) {
        if (worstSizes[i] > largest2) {
            largest2 = worstSizes[i];
            largestIdx2 = i;
        }
    }
    worstSizes.erase(worstSizes.begin() + largestIdx2);
    worstSizes.push_back(largest + largest2);
    int cnt = 0;
    for (int j = 0; j < worstSizes.size(); j++) {
        for (int k = j + 1; k < worstSizes.size(); k++) {
            cnt += worstSizes[j] * worstSizes[k];
        }
    }
    cout << cnt << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
