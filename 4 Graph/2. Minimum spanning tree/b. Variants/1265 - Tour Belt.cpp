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


int N, M, T;

// u is the element of current set we want to check
int counter(int u, UnionFind &UF, const vector<iii> &edges) {
    int ans = 0, minInsideEdge = INT_MAX, maxBorderEdge = INT_MIN, uSet = UF.findSet(u);
    for (int i = 0; i < M; ++i) {
        int xSet = UF.findSet(get<1>(edges[i])), ySet = UF.findSet(get<2>(edges[i])), w = get<0>(edges[i]);
        if (xSet == uSet && ySet == uSet) { // this edge point from inner node to inner node,get worst inside edge
            minInsideEdge = min(minInsideEdge, w);
        } else if (xSet == uSet || ySet == uSet) { // this edge point from inner node to outside node,get worst border edge
            maxBorderEdge = max(maxBorderEdge, w);
        }
    }
    if (minInsideEdge <= maxBorderEdge) return 0;
    for (int i = 0; i < N; ++i) {
        if (UF.findSet(i) == uSet) ans++;
    }
    return ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> T;
    while (T--) {

        cin >> N >> M;
        vector<iii> edges;
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            edges.emplace_back(w, u, v);
        }
        sort(edges.begin(), edges.end(), greater<vector<iii>::value_type>());

        int num_taken = 0, ans = 0;
        UnionFind UF(N);
        for (int i = 0; i < M; i++) {
            auto [w, u, v] = edges[i]; // don't use pq here cuz we want the whole edges list
            if (UF.isSameSet(u, v)) continue;
            num_taken++;
            UF.unionSet(u, v);
            ans += counter(u, UF, edges); // doesn't matter u or v since they are in the same set
            if (num_taken == N - 1) break;
        }
        cout << ans << endl;

    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

