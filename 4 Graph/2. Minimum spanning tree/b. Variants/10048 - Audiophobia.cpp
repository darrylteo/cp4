#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;                           // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }

    int numDisjointSets() { return numSets; }

    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

// graph is connected by a single path. dfs to find path and print worst edge
vector<pair<int, int>> adj[105];
int visited[105];
vector<int> ans;
void dfs(int start, int end) {
    visited[start] = 1;
    if (start == end) return;
    for (auto &[v, w] : adj[start]) {
        if (!visited[v]) {
            ans.push_back(w);
            dfs(v, end);
            if (visited[end]) return;
            ans.pop_back(); // remove it if it doesn't lead to end
        }
    }
}

// wasted time trying to find a shortcut or memoization but the naive solution works and speed is around median submission

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q, cases = 1;
    while (cin >> N >> M >> Q, N) {
        // using pq so no need sort
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> edges;
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.emplace(w, u - 1, v - 1);
        }
        int mst_cost = 0;
        int num_taken = 0;
        UnionFind UF(N);
        for (int i = 0; i < N; i++) adj[i].clear();
        while (!edges.empty()) {
            auto [w, u, v] = edges.top();
            edges.pop();
            if (UF.isSameSet(u, v)) continue;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            mst_cost += w;
            num_taken++;
            UF.unionSet(u, v);
            if (num_taken == N - 1) break;
        }

        if (cases > 1) cout << endl;
        cout << "Case #" << cases++ << endl;
        while (Q--) {
            int start, end;
            cin >> start >> end;
            start--, end--;
            memset(visited, 0, sizeof(visited));
            ans.clear();
            dfs(start, end);
            if (!visited[end]) {
                cout << "no path" << endl;
                continue;
            }
            cout << *max_element(ans.begin(), ans.end()) << endl;
        }

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}