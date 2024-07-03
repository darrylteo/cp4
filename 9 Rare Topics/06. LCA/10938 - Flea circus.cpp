#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

typedef vector<int> vi;

vector<vi> children;

vi L, E, H;
int idx, N;

class SparseTable {                              // OOP style
private:
    vi A, P2, L2;
    vector<vi> SpT;                                // the Sparse Table
public:
    SparseTable() {}                               // default constructor

    SparseTable(vi &initialA) {                    // pre-processing routine
        A = initialA;
        int n = (int) A.size();
        int L2_n = (int) log2(n) + 1;
        P2.assign(L2_n + 1, 0);
        L2.assign((1 << L2_n) + 1, 0);
        for (int i = 0; i <= L2_n; ++i) {
            P2[i] = (1 << i);                            // to speed up 2^i
            L2[(1 << i)] = i;                            // to speed up log_2(i)
        }
        for (int i = 2; i < P2[L2_n]; ++i)
            if (L2[i] == 0)
                L2[i] = L2[i - 1];                         // to fill in the blanks

        // the initialization phase
        SpT = vector<vi>(L2[n] + 1, vi(n));
        for (int j = 0; j < n; ++j)
            SpT[0][j] = j;                             // RMQ of sub array [j..j]

        // the two nested loops below have overall time complexity = O(n log n)
        for (int i = 1; P2[i] <= n; ++i)             // for all i s.t. 2^i <= n
            for (int j = 0; j + P2[i] - 1 < n; ++j) {      // for all valid j
                int x = SpT[i - 1][j];                     // [j..j+2^(i-1)-1]
                int y = SpT[i - 1][j + P2[i - 1]];             // [j+2^(i-1)..j+2^i-1]
                SpT[i][j] = A[x] <= A[y] ? x : y;
            }
    }

    int RMQ(int i, int j) {
        int k = L2[j - i + 1];                           // 2^k <= (j-i+1)
        int x = SpT[k][i];                           // covers [i..i+2^k-1]
        int y = SpT[k][j - P2[k] + 1];                   // covers [j-2^k+1..j]
        return A[x] <= A[y] ? x : y;
    }
};

void dfs(int cur, int depth) {
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;
    for (auto &nxt: children[cur]) {
        dfs(nxt, depth + 1);
        E[idx] = cur;                              // backtrack to current node
        L[idx++] = depth;
    }
}

void buildRMQ() {
    idx = 0;
    H.assign(N, -1);
    L.assign(2 * N, 0);
    E.assign(2 * N, 0);
    dfs(0, 0);                       // we assume that the root is at index 0
}

int LCA(int u, int v, SparseTable &spT) { // spT will be built using L
    if (H[u] > H[v]) swap(u, v);
    return E[spT.RMQ(H[u], H[v])];
}

// code mostly from book website

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> N, N) {
        // we will root the tree at node 0
        vector<vi> adj(N);
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // bfs to fill in the children array
        children.assign(N, vi());
        queue<int> q;
        q.push(0);
        vector<bool> visited(N, false);
        visited[0] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &nxt: adj[cur]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    children[cur].push_back(nxt);
                    q.push(nxt);
                }
            }
        }
        // get parent so we can traverse up the tree
        vi parent(N, -1);
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &nxt: children[cur]) {
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
        // build LCA RMQ
        buildRMQ();
        SparseTable spT(L);
        int Q;
        cin >> Q;
        for (int i = 0; i < Q; ++i) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            int meet = LCA(u, v, spT);
            // get path from u to meet
            vi pathU;
            while (u != meet) {
                pathU.push_back(u);
                u = parent[u];
            }
            // get path from v to meet
            vi pathV;
            while (v != meet) {
                pathV.push_back(v);
                v = parent[v];
            }
            // get full path
            vi path;
            for (int j: pathU) path.push_back(j);
            path.push_back(meet);
            reverse(pathV.begin(), pathV.end());
            for (int j: pathV) path.push_back(j);
            // if odd can meet
            if (path.size() % 2 == 1) {
                cout << "The fleas meet at " << path[path.size() / 2] + 1 << ".\n";
            } else {
                int a = path[path.size() / 2], b = path[path.size() / 2 - 1];
                if (a > b) swap(a, b);
                cout << "The fleas jump forever between " << a + 1 << " and " << b + 1 << ".\n";
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}