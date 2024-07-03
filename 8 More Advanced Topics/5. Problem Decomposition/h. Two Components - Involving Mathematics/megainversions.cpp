#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<class T> // later, we will choose a tree that is (value, index)
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
ll hi[100000], lo[100000];
vi z;
ll ans = 0;

// new resource: https://usaco.guide/problems/kattis-mega-inversions/solution

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    z.resize(n);
    for (int &i: z) cin >> i;

    Tree<pii> T1;
    for (int i = 0; i < n; i++) {
        hi[i] = T1.size() - T1.order_of_key({z[i], 1e9}); // number of elements strictly greater than z[i] on the left
        T1.insert({z[i], i});
    }

    Tree<pii> T2;
    for (int i = n - 1; i >= 0; i--) {
        lo[i] = T2.order_of_key({z[i], -1}); // number of elements strictly less than z[i] on the right
        T2.insert({z[i], i});
    }

    for (int i = 0; i < n; i++) {
        ans += hi[i] * lo[i]; // count the triples. not about swapping e.g. 3 3 3 2 1 1 1 1. total 3*4 triples.
    }
    cout << ans << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
