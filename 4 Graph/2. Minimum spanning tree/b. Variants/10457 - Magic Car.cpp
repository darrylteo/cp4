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

// bruh ... the sample test case and udebug case didn't have multiple test cases. -_-. so many WA attempts

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;

    while (cin >> N >> M) {
        vector<iii> edges;
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            edges.emplace_back(w, u, v);
        }
        // greater or less is ok. we will take all contiguous subsets (max - min = energy so take close together weights)
        sort(edges.begin(), edges.end());

        int a, b;
        cin >> a >> b;

        int c;
        cin >> c;
        while (c--) {
            int start, end;
            cin >> start >> end;
            start--, end--;
            int ans = INT_MAX;
            for (int i = 0; i < M; ++i) {
                UnionFind UF(N); // reset
                for (int j = i; j < M; ++j) { // for each subset starting with i and ending with j.
                    UF.unionSet(get<1>(edges[j]), get<2>(edges[j])); // link them
                    if (UF.isSameSet(start, end)) {
                        ans = min(ans, get<0>(edges[j]) - get<0>(edges[i])); // sorted ascending so j >= i
                        break; // this is already the best answer starting from i
                    }
                }
            }
            cout << ans + a + b << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

