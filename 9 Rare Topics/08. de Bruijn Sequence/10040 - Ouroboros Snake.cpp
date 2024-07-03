#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int m, v, k; // path length we are on, number of nodes, kth node, k from qn
vector<vi> adjList, path;

void hierholzer(int s) {
    vi idx(v), st;
    st.emplace_back(s);
    while (!st.empty()) {
        int u = st.back();
        if (idx[u] < adjList[u].size()) {
            st.emplace_back(adjList[u][idx[u]]);
            idx[u]++;
        } else {
            path[m].emplace_back(u & 1);
            st.pop_back();
        }
    }
    path[m].pop_back(); // probably because source will visit itself
    reverse(path[m].begin(), path[m].end());
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_9_Rare_Topics/9.10_De_Bruijn_Sequence/vjudge_UVA-10040_Ouroboros_Snake.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    path.assign(22, vi());
    path[0] = {0, 1};
    for (m = 1; m < 22; ++m) {
        v = 1 << m;
        adjList.assign(v, vi(2));
        for (int i = 0; i < v; ++i) {
            int q = i & ((v >> 1) - 1); // same as bitshift right and left to remove the 1 bit
            q <<= 1;
            adjList[i][0] = q;
            adjList[i][1] = q | 1;
        }
        hierholzer(v - 1);
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> m >> k;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans <<= 1;
            ans += path[m - 1][(k + i) % path[m - 1].size()];
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
