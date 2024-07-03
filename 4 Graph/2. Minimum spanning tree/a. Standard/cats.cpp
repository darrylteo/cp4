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

// M - C is the max distance u can walk

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int M, C;
        cin >> M >> C;
        // using pq so no need sort
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> edges;
        for (int i = 0; i < C * (C - 1) / 2; i++) {
            int c1, c2, dist;
            cin >> c1 >> c2 >> dist;
            edges.emplace(dist, c1, c2);
        }
        int mst_cost = 0;
        int num_taken = 0;
        UnionFind UF(C);
        while(true) {
            auto [w, u, v] = edges.top();
            edges.pop();
            if (UF.isSameSet(u, v)) continue;
            mst_cost += w;
            UF.unionSet(u, v);
            num_taken++;
            if (num_taken == C - 1) break;
        }

        if (mst_cost <= M - C) cout << "yes\n";
        else cout << "no\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}