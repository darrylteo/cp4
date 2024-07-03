// https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/fenwicktree_ds.cpp
// https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/segmenttree_ds.cpp

#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))                    // the key operation

typedef long long ll;                            // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {                              // index 0 is not used
private:
    vll ft;                                        // internal FT is an array
public:
    FenwickTree(int m) { ft.assign(m + 1, 0); }      // create an empty FT

    void build(const vll &f) {
        int m = (int) f.size() - 1;                     // note f[0] is always 0
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i) {               // O(m)
            ft[i] += f[i];                             // add this value
            if (i + LSOne(i) <= m)                       // i has parent
                ft[i + LSOne(i)] += ft[i];                 // add to that parent
        }
    }

    FenwickTree(const vll &f) { build(f); }        // create FT based on f

    FenwickTree(int m, const vi &s) {              // create FT based on s
        vll f(m + 1, 0);
        for (int i = 0; i < (int) s.size(); ++i)      // do the conversion first
            ++f[s[i]];                                 // in O(n)
        build(f);                                    // in O(m)
    }

    ll rsq(int j) {                                // returns RSQ(1, j)
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, ll v) {
        for (; i < (int) ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    int select(ll k) {                             // O(log m)
        int p = 1;
        while (p * 2 < (int) ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

class RUPQ {                                     // RUPQ variant
private:
    FenwickTree ft;                                // internally use PURQ FT
public:
    RUPQ(int m) : ft(FenwickTree(m)) {}

    void range_update(int ui, int uj, ll v) {
        ft.update(ui, v);                            // [ui, ui+1, .., m] +v
        ft.update(uj + 1, -v);                         // [uj+1, uj+2, .., m] -v
    }                                              // [ui, ui+1, .., uj] +v
    ll point_query(int i) { return ft.rsq(i); }    // rsq(i) is sufficient
};

class RURQ {                                    // RURQ variant
private:                                         // needs two helper FTs
    RUPQ rupq;                                     // one RUPQ and
    FenwickTree purq;                              // one PURQ
public:
    RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} // initialization
    void range_update(int ui, int uj, ll v) {
        rupq.range_update(ui, uj, v);                // [ui, ui+1, .., uj] +v
        purq.update(ui, v * (ui - 1));                   // -(ui-1)*v before ui
        purq.update(uj + 1, -v * uj);                    // +(uj-ui+1)*v after uj
    }

    ll rsq(int j) {
        return rupq.point_query(j) * j -               // optimistic calculation
               purq.rsq(j);                          // cancelation factor
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // standard
};

class SegmentTree {                              // OOP style
private:
    int n;                                         // n = (int)A.size()
    vi A, st, lazy;                                // the arrays

    int l(int p) { return p << 1; }                 // go to left child
    int r(int p) { return (p << 1) + 1; }              // go to right child

    int conquer(int a, int b) {
        if (a == -1) return b;                       // corner case
        if (b == -1) return a;
        return min(a, b);                            // RMQ
    }

    void build(int p, int L, int R) {              // O(n)
        if (L == R)
            st[p] = A[L];                              // base case
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {                         // has a lazy flag
            st[p] = lazy[p];                           // [L..R] has same value
            if (L != R)                                // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
            else                                       // L == R, a single index
                A[L] = lazy[p];                          // time to update this
            lazy[p] = -1;                              // erase lazy flag
        }
    }

    int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return -1;                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] = val;                             // update this
            propagate(p, L, R);                        // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
        }
    }

public:
    SegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n, -1) {}

    SegmentTree(const vi &initialA) : SegmentTree((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

// keep track of the positions for each gem type using 1 and 0
// rupq.rsq(L, R) * value for each gem type
// just follow clue... anyway need long long since 1 gem can already be 10^9
// title is a reference to my little pony
// https://mlp.fandom.com/wiki/Just_for_Sidekicks

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> gemValue(7);
    for (int i = 1; i < 7; ++i) {
        cin >> gemValue[i];
    }
    vector<FenwickTree> gemType(7, FenwickTree(N));
    string s;
    cin >> s;
    for (int i = 0; i < N; ++i) {
        gemType[s[i] - '0'].update(i + 1, 1);
    }
    int queryType;
    for (int i = 0; i < Q; ++i) {
        cin >> queryType;
        if (queryType == 1) {
            int K, P;
            cin >> K >> P;
            gemType[s[K - 1] - '0'].update(K, -1); // s[K - 1] - '0' is the gem type currently in s
            s[K - 1] = P + '0';
            gemType[P].update(K, 1);
        } else if (queryType == 2) {
            int P, V;
            cin >> P >> V;
            gemValue[P] = V;
        } else {
            int L, R;
            cin >> L >> R;
            ll ans = 0;
            for (int j = 1; j < 7; ++j) {
                ans += gemType[j].rsq(L, R) * gemValue[j];
            }
            cout << ans << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
