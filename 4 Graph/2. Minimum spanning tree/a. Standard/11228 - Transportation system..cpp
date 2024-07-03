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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int N, R;
        cin >> N >> R;
        int R2 = R * R;
        vector<pair<int, int>> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].first >> points[i].second;
        }
        // using pq so no need sort
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> edges;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int w = (points[i].first - points[j].first) * (points[i].first - points[j].first) +
                        (points[i].second - points[j].second) * (points[i].second - points[j].second);
                edges.emplace(w, i, j);
            }
        }
        double mst_cost_roads = 0, mst_cost_railroads = 0;
        int num_taken = 0, railroads = 0;
        UnionFind UF(N);
        while (!edges.empty()) {
            auto [w, u, v] = edges.top();
            edges.pop();
            if (UF.isSameSet(u, v)) continue;

            if (w <= R2) {
                mst_cost_roads += sqrt(w);
            } else {
                mst_cost_railroads += sqrt(w);
                railroads++;
            }

            num_taken++;
            UF.unionSet(u, v);
            if (num_taken == N - 1) break;
        }

        cout << "Case #" << cases << ": " << railroads + 1 << " " << round(mst_cost_roads) << " " << round(mst_cost_railroads) << endl;

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}