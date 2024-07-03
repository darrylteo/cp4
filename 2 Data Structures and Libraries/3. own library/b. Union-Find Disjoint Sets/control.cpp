// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
// https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/unionfind_ds.cpp
#include <bits/stdc++.h>

using namespace std;

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

    int numDisjointSets() { return numSets; }      // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, potCnt = 0;
    cin >> N;
    UnionFind UF(500001);
    while (N--) {
        int n, ingredientCnt = 0;
        cin >> n;
        bool passCase = true;
        // just to store "header" values of this row
        // from example, first pot has ingredients 1 and 2, after union, let's say 1 is the header
        // in 4th pot, when adding ingredient 1, by adding "header" 1, we add the whole pot containing ingredient 1
        unordered_set<int> v;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (passCase) { // if we already have more ingredients than needed... just cin and skip checks
                if (v.find(UF.findSet(x)) == v.end()) { // if header not in yet
                    v.insert(UF.findSet(x)); // insert header
                    ingredientCnt += UF.sizeOfSet(x); // add the whole pot
                }
                if (ingredientCnt > n) {
                    passCase = false;
                }
            }
        }

        if (passCase) {
            int header = *v.begin();
            for (auto &i: v) {
                UF.unionSet(header, i);
            }
            potCnt++;
        }

    }
    cout << potCnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
