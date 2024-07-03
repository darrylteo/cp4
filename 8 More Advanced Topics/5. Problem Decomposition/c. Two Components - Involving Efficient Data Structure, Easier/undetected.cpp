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

struct circle {
    int x, y, r;
};

bool overlap(circle c1, circle c2) {
    return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) <= (c1.r + c2.r) * (c1.r + c2.r);
}

// if a circle touching left is same set as a circle touching right, we have blocked the path (from y=0 to y=300)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<circle> circles(n);
    vector<int> left, right;
    for (int i = 0; i < n; i++) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
        if (circles[i].x - circles[i].r <= 0) left.push_back(i);
        if (circles[i].x + circles[i].r >= 200) right.push_back(i);
    }
    int k = 0;
    UnionFind uf(n);
    while (true) {
        for (int i = 0; i < k; ++i) { // adding current circle k to any previous sets
            if (overlap(circles[k], circles[i])) uf.unionSet(k, i);
        }
        for (int l: left)
            for (int r: right)
                if (uf.isSameSet(l, r)) {
                    cout << k << endl;
                    return 0;
                }
        k++;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
