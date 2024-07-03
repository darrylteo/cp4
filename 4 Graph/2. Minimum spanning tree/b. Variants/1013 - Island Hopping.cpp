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
vector<int> adj[105];
int visited[105], prevVisited[105];
void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cases = 1;
    while (cin >> N, N) {
        vector<pair<int, int>> points(N);
        vector<int> peepo(N);
        int sumPeepo = 0;
        for (int i = 0; i < N; i++) {
            cin >> points[i].first >> points[i].second >> peepo[i];
            sumPeepo += peepo[i];
        }
        // using pq so no need sort
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> edges;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                double w = sqrt((points[i].first - points[j].first) * (points[i].first - points[j].first) +
                        (points[i].second - points[j].second) * (points[i].second - points[j].second));
                edges.emplace(w, i, j);
            }
        }

        int num_taken = 0;
        vector<tuple<double, int, int>> mst_edges;
        UnionFind UF(N);
        for (int i = 0; i < N; i++) adj[i].clear();
        while (!edges.empty()) {
            auto [w, u, v] = edges.top();
            edges.pop();
            if (UF.isSameSet(u, v)) continue;
            mst_edges.emplace_back(w, u, v);
            num_taken++;
            UF.unionSet(u, v);
            if (num_taken == N - 1) break;
        }

        // everytime we add the lowest edge, run dfs and anything that is colored now but not previously, add to sumNumerator
        sort(mst_edges.begin(), mst_edges.end());

        for (int i = 0; i < N; i++) adj[i].clear();
        memset(visited, 0, sizeof visited);
        memset(prevVisited, 0, sizeof prevVisited);

        double sumNumerator = 0;

        for (auto &[w, u, v] : mst_edges) {
            // add the shortest time to build edge
            adj[u].push_back(v);
            adj[v].push_back(u);
            memset(visited, 0, sizeof visited);
            dfs(0);
            for (int i = 1; i < N; i++) {
                if (visited[i] && !prevVisited[i]) {
                    sumNumerator += peepo[i] * w;
                }
                prevVisited[i] = visited[i]; // copy constructor
            }
        }

        cout << "Island Group: " << cases++ << " Average " << fixed << setprecision(2) << sumNumerator / sumPeepo << "\n\n";

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

