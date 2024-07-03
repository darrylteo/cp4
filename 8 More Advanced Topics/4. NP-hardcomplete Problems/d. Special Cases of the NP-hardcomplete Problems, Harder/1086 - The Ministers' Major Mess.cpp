#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505; // 500 ministers (nodes)
class TwoSat {
public:
    int n;
    vector<int> g[MAXN]; // adjacency list directed graph
    // scc stuff. used morris implementation rather than halim for this qn.
    int vfind[MAXN], findIdx;
    int stk[MAXN], stkIdx;
    int in_stk[MAXN], visited[MAXN];
    int contract[MAXN];
    int scc_cnt;

    int scc(int u) {
        in_stk[u] = visited[u] = 1;
        stk[++stkIdx] = u, vfind[u] = ++findIdx;
        int mn = vfind[u], v;
        for (int i: g[u]) {
            v = i;
            if (!visited[v]) mn = min(mn, scc(v));
            if (in_stk[v]) mn = min(mn, vfind[v]);
        }
        if (mn == vfind[u]) {
            do {
                in_stk[stk[stkIdx]] = 0;
                contract[stk[stkIdx]] = u;
            } while (stk[stkIdx--] != u);
            scc_cnt++;
        }
        return mn;
    }

    void addEdge(int u, int v) { // u -> v
        g[u].push_back(v);
    }

    bool solvable() {
        for (int i = 0; i < n; ++i) visited[i] = in_stk[i] = 0;
        scc_cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                findIdx = stkIdx = 0;
                scc(i);
            }
        }
        for (int i = 0; i < n; i += 2) {
            if (contract[i] == contract[i ^ 1]) return false; // same SCC
        }
        return true;
    }

    void computeChoice() {
        for (int i = 0; i < n; i += 2) {
            int val = 0;
            g[i].push_back(i ^ 1); // NO implies YES is ok??
            if (solvable()) val |= 1;
            g[i].pop_back();

            g[i ^ 1].push_back(i); // YES implies NO is ok??
            if (solvable()) val |= 2;
            g[i ^ 1].pop_back();

            cout << "-yn?"[val];
        }
        cout << '\n';
    }

    void init(int nn) {
        this->n = nn;
        for (int i = 0; i < nn; ++i) g[i].clear();
    }
} g;


// ref: https://github.com/morris821028/UVa/blob/master/volume010/1086%20-%20The%20Ministers'%20Major%20Mess.cpp
// even nodes are NO, odd nodes are YES
// must answer more than half so if 1 or 2 votes, all must correct. if 3 or 4, at most 1 can be wrong.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, cases = 1;
    string s;
    while (cin >> n >> m, n) {
        g.init(n * 2);
        for (int i = 0; i < m; ++i) {
            int k, x, vote[4];
            cin >> k;
            for (int j = 0; j < k; ++j) {
                cin >> x >> s;
                x--;
                vote[j] = x * 2 + (s[0] == 'y'); // even nodes are NO, odd nodes are YES
            }
            if (k <= 2) {
                for (int j = 0; j < k; ++j) {
                    g.addEdge(vote[j] ^ 1, vote[j]); // NO implies YES
                }
            } else {
                for (int j = 0; j < k; ++j) {
                    for (int jj = 0; jj < k; ++jj) {
                        if (j != jj) g.addEdge(vote[j] ^ 1, vote[jj]); // j = NO implies all other must be YES
                    }
                }
            }
        }
        cout << "Case " << cases++ << ": ";
        if (!g.solvable()) {
            cout << "impossible\n";
        } else {
            g.computeChoice();
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}