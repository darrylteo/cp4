// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
// https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/unionfind_ds.cpp
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
    vi p, rank, setSize, remainingSize;     // ***    // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
        remainingSize.assign(N, 1);                 // ***
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }      // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) {
            remainingSize[findSet(i)]--; // ***
            return;                 // i and j are in same set
        }
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
        remainingSize[y] = remainingSize[x] + remainingSize[y] - 1; // ***
    }

    int remainingSpace(int i) { return remainingSize[findSet(i)]; } // ***
};

// general strategy: union the sets which contain both numbers, sum the remaining spaces, -1 for this new set
// edited above template with remainingSize variable with ***
// weird how most C++ code is in the 0.05s bracket... but mine 0.43s already is slightly faster than other UFDS i copy pasted from online to test

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;
    UnionFind uf(L + 1); // 1 to L

    for (int i = 0; i < N; ++i) {
        int a, b, spacea, spaceb;
        cin >> a >> b;
        // find remaining space of set a and b
        spacea = uf.remainingSpace(a);
        spaceb = uf.remainingSpace(b);
        if (spacea == 0 && spaceb == 0) {
            cout << "SMECE" << endl;
            continue;
        }
        uf.unionSet(a, b);
        cout << "LADICA" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
