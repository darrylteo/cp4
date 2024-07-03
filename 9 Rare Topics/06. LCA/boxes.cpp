#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<vi> children;

vi L, E, H, subSize;
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
    subSize[cur] = 1;
    for (auto &nxt: children[cur]) {
        dfs(nxt, depth + 1);
        E[idx] = cur;                              // backtrack to current node
        L[idx++] = depth;
        subSize[cur] += subSize[nxt];
    }
}

void buildRMQ() {
    idx = 0;
    H.assign(N, -1);
    L.assign(2 * N, 0);
    E.assign(2 * N, 0);
    subSize.assign(N, 0);
    dfs(0, 0);                       // we assume that the root is at index 0
}

int LCA(int u, int v, SparseTable &spT) { // spT will be built using L
    if (H[u] > H[v]) swap(u, v);
    return E[spT.RMQ(H[u], H[v])];
}

// code mostly from book website
// additionally, we keep track of the sub of each subtree starting at node curr
// we then check in O(20^2) if node i is a descendant of node j (if LCA of i and j is j) for all j
// if not contained in any subtree, we add the subtree size to the answer

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N;
    N++; // actually 0 indexed since we add node 0
    children.assign(N, vi()); // node 0 is the root
    for (int i = 1; i < N; i++) {
        int x;
        cin >> x;
        children[x].push_back(i);
    }
    buildRMQ();
    SparseTable spT(L);
    int Q;
    cin >> Q;
    while (Q--) {
        int M;
        cin >> M;
        vi nodes(M); // nodes to check
        for (int i = 0; i < M; i++) cin >> nodes[i];
        int ans = 0;
        for (int i = 0; i < M; i++) {
            int ok = 1;
            for (int j = 0; j < M; j++) {
                if (i == j) continue;
                if (LCA(nodes[i], nodes[j], spT) == nodes[j]) {
                    ok = 0; // contained in subtree
                    break;
                }
            }
            if (ok) ans += subSize[nodes[i]];
        }
        cout << ans << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}