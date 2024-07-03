// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
// https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/unionfind_ds.cpp
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
    vi p, rank, setSize, fakeNode;                           // vi p is the key part
    int fakeIdx;
    vector<long long> sumSet; // ***
public:
    UnionFind(int N) {
        p.assign(N + 1, 0);
        for (int i = 0; i < N + 1; ++i) p[i] = i;
        rank.assign(N + 1, 0);                           // optional speedup
        sumSet.assign(N + 1, 0);
        for (int i = 1; i < N + 1; ++i) sumSet[i] = i; // ***
        setSize.assign(N + 1, 1);                        // optional feature
        fakeNode.assign(N + 1, 0);
        for (int i = 1; i < N + 1; ++i) fakeNode[i] = i; // ***
        fakeIdx = N + 1;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int sizeOfSet(int i) { return setSize[findSet(fakeNode[i])]; } // optional


    void unionSet(int i, int j) {
        if (isSameSet(fakeNode[i], fakeNode[j])) return;                 // i and j are in same set
        int x = findSet(fakeNode[i]), y = findSet(fakeNode[j]);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        sumSet[y] += sumSet[x]; // ***
    }

    long long sumOfSet(int i) {
        return sumSet[findSet(fakeNode[i])];
    } // ***

    //  we should leave node i in its original set, but add a new (single node) set and add to set j
    void moveSet(int i, int j) {
        if (isSameSet(fakeNode[i], fakeNode[j])) return;                 // i and j are in same set
        // add a fake variable
        p.push_back(fakeIdx);
        rank.push_back(0);
        sumSet.push_back(i);
        setSize.push_back(1);

        // remove value from old set
        sumSet[findSet(fakeNode[i])] -= i;
        setSize[findSet(fakeNode[i])] -= 1;

        // add value to new set
        fakeNode[i] = fakeIdx++;
        unionSet(i, j);
    }

};

// HARD... btw it's super weird that in uva 11987 - Almost Union-Find. we can just submit without fake nodes ... i.e. just breaking the tree is OK
// added new variable to compute sum of elements in a set
// fake variables are a number beyond the range of the original set
// always use these for any join or move operations
// e.g. if i move 5 from set {4 <- 5 <- 1} to set {3 <- 2}, with fakeNodes = {1, 2, 3, 4, 5}, then
// the new sets will be {4 <- 5 <- 1} and {3 <- 2 <- 6} with fakeNodes = {1, 2, 3, 4, 6}
// so 1 still has parent 5 which has parent 4 since findSet uses p[] and not fakeNode[]
// it doesn't matter if 5 is the header as it becomes a placeholder "header" to mark which set 1 belongs to
// but when we move or union 5 again it will use fake node. so let's say we union 5 and 4.
// we will unionSet(6, 4) and since header of 6 is 3 so whole 2nd tree gets unioned to 1st tree as expected

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        UnionFind uf(n);
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if (x == 1) {
                int a, b;
                cin >> a >> b;
                uf.unionSet(a, b);
            } else if (x == 2) {
                int a, b;
                cin >> a >> b;
                uf.moveSet(a, b);
            } else {
                int a;
                cin >> a;
                cout << uf.sizeOfSet(a) << " " << uf.sumOfSet(a) << endl;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
