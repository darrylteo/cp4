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

const int MAXT = (1e+7) + 5;
static const int MAXN = 32;
static const int MAXM = 1<<24;
static int n, miss[MAXN], cache[MAXN];
static int stamp[MAXM], mtime;

// tree keeps track of how many DIFFERENT addresses were accessed in a given time range
// underlying data is just 1 and 0. 1 if it is a DIFFERENT address, 0 if not
// tree is needed for quick RSQ
void access(int addr, FenwickTree &tree) {
    int &st = stamp[addr]; // records exactly when this addr was last visited
    if (st == 0) {
        for (int i = 0; i < n; i++)
            miss[i]++;
    } else {
        // from last visit to now, how many DIFFERENT addresses were accessed?
        int cnt = tree.rsq(st, mtime);
        for (int i = 0; i < n && cnt > cache[i]; i++)
            miss[i]++;
        // -1 so don't count it as a DIFFERENT address
        tree.update(st, -1);
    }
    st = ++mtime; // update when this addr was last visited
    tree.update(st, 1);
}

// again i don't know how do. had to refer to soln. next time maybe come back practice this topic
// https://github.com/morris821028/UVa/blob/master/volume114/11423%20-%20Cache%20Simulator.cpp
// i can understand the soln but i would not have thought of it

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cache[i];
    memset(stamp, 0, sizeof(stamp));
    mtime = 0;
    FenwickTree tree(MAXT);

    int addr, b, y, k;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "RANGE") {
            cin >> b >> y >> k;
            for (int i = 0; i < k; i++)
                access(b + i * y, tree);
        } else if (cmd == "ADDR") {
            cin >> addr;
            access(addr, tree);
        } else if (cmd == "STAT") {
            for (int i = 0; i < n; i++)
                cout << miss[i] << " \n"[i == n - 1];
            memset(miss, 0, sizeof(miss));
        }
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
