#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & (-S))

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class FenwickTree {                              // index 0 is not used
private:
    vector<bitset<105>> ft;
public:
    explicit FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

    bitset<105> rsq(int j) {                                // returns odd lights bitset. we don't use this
        bitset<105> sum;
        for (; j; j -= LSOne(j)) sum ^= ft[j];
        return sum;
    }

    ull rsq(int i, int j) { return (rsq(j) ^ rsq(i-1)).count(); } // returns count of odd lights
    void update(int i, bitset<105> v) {
        for (; i < (int)ft.size(); i += LSOne(i)) ft[i] ^= v;
    }
};

vi visited;
vvi adj;
vii subtree;

// dfs to calculate subtree start and end idx in fenwick tree
int idx = 1; // fenwick tree is 1-indexed
inline void dfs(int u) {
    visited[u] = true;
    subtree[u].first = idx++;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
    subtree[u].second = idx-1;
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_8_Advanced_Topics/8.7_Problem_Decomposition/kattis_magicallights.cpp
// each node in the FT will store a bitset<105> where bitset[i] = 1 if the color i is odd in the subtree

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    FenwickTree ft(N);
    vi colors(N);
    subtree.resize(N);
    visited.assign(N, false);
    adj.resize(N);
    for (int &i: colors) cin >> i;
    for (int i = 1; i < N; ++i) {
        int u;
        cin >> u;
        u--;
        adj[u].push_back(i);
    }
    // initialize
    dfs(0);
    for (int i = 0; i < N; ++i) {
        bitset<105> bs;
        bs[colors[i]] = true;
        ft.update(subtree[i].first, bs);
    }
    // do queries
    for (int q = 0; q < Q; ++q) {
        int K, X;
        cin >> K >> X;
        X--;
        if (K == 0) {
            cout << ft.rsq(subtree[X].first, subtree[X].second) << endl;
        } else {
            bitset<105> v;
            v[colors[X]] = true;
            ft.update(subtree[X].first, v); // remove the old color
            colors[X] = K; // update in the array
            v.reset();
            v[K] = true;
            ft.update(subtree[X].first, v); // add the new color
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}

