#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind { // OOP style
private:
    vi p, rank, setSize; // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0); // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N; // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; } // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return; // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y]) swap(x, y); // keep x ’shorter’ than y
        p[x] = y; // set x under y
        if (rank[x] == rank[y]) ++rank[y]; // optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        --numSets; // a union reduces numSets
    }
};

vector<vector<pair<int, int>>> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k, d, x, y, b;
        cin >> n >> m >> k >> d;
        UnionFind uf(m + n); // docs are 0 to m-1 and trees are m to m+n-1
        v.assign(m + n, vector<pair<int, int>>()); // branches. incl docs at start
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            v[i].emplace_back(x, y);
        }
        for (int i = 0; i < n; ++i) {
            cin >> b;
            while (b--) {
                cin >> x >> y;
                v[m + i].emplace_back(x, y);
            }
        }
        for (int i = 0; i < m + n; ++i) {
            for (int j = i + 1; j < m + n; ++j) {
                int min_dist = INT_MAX;
                for (auto &p1 : v[i]) {
                    for (auto &p2 : v[j]) {
                        int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
                        min_dist = min(min_dist, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                    }
                }
                // use d if connecting with docs, k if connecting trees
                if ((min_dist <= d * d && (i < m || j < m)) || (min_dist <= k * k && i >= m && j >= m)) {
                    uf.unionSet(i, j);
                }
            }
        }
        int found = 0;
        for (int i = 0; i < m; ++i) {
            if (uf.isSameSet(m, i)) { // idx m is tree 0
                found = 1;
                break;
            }
        }
        cout << (found ? "Tree can be saved :)" : "Tree can't be saved :(") << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
