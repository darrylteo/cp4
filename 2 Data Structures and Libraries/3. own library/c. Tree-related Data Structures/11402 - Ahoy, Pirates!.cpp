// https://lbv-pc.blogspot.com/2012/10/ahoy-pirates_24.html
#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024000
#define MAXH 21  // 1 + ceil(log2(MAXN))

// Flags to identify states. 0 is for "Nothing".
#define UP_SET 1
#define UP_CLR 2
#define UP_FLP 3

struct SegTree {
    vector<int> A;  // original array of integers
    vector<int> T;  // segment tree
    vector<int> U;  // segment tree for lazy propagation (the states)

    int n;  // size of the array

    SegTree(int N = 0) : n(N) {
        A.resize(MAXN); // notice A has the least nodes. the rest have 2x nodes as they are the tree
        T.resize(1 << MAXH);
        U.resize(1 << MAXH);
    }

    // 0 and n-1 are the bounds of the array (from reference website it is 0:7)
    void init() { tree_init(1, 0, n - 1); }

    void tree_init(int x, int a, int b) {
        U[x] = 0;
        // set value from pirate array A if reach leaf
        if (a == b) {
            T[x] = A[a];
            return;
        }
        int lt = 2 * x, rt = lt + 1, md = (a + b) / 2;
        tree_init(lt, a, md);
        tree_init(rt, md + 1, b);
        // sum up the values from the children
        T[x] = T[lt] + T[rt];
    }

    void set(int i, int j) { tree_set(i, j, 1, 0, n - 1); }

    // again here we have a and b as the range
    void tree_set(int i, int j, int x, int a, int b) {
        propagate(x, a, b);
        // almost same as building tree but break once out of bounds
	// i.e. stop propagating
	// here j < a implies j < a && j < b since a < b. same for i < b.
        if (j < a || i > b) return;
        if (a == b) {
            T[x] = 1;
            return;
        }
        int lt = 2 * x, rt = lt + 1, md = (a + b) / 2;
        // or set all also can break early
        if (a >= i && b <= j) {
            T[x] = b - a + 1;
            U[lt] = U[rt] = UP_SET;
            return;
        }
        tree_set(i, j, lt, a, md);
        tree_set(i, j, rt, md + 1, b);
        T[x] = T[lt] + T[rt];
    }

    void clear(int i, int j) { tree_clear(i, j, 1, 0, n - 1); }

    void tree_clear(int i, int j, int x, int a, int b) {
        propagate(x, a, b);
        if (j < a || i > b) return;
        if (a == b) {
            T[x] = 0;
            U[x] = 0;
            return;
        }
        int lt = 2 * x, rt = lt + 1, md = (a + b) / 2;
        if (a >= i && b <= j) {
            T[x] = 0;
            U[lt] = U[rt] = UP_CLR;
            return;
        }
        tree_clear(i, j, lt, a, md);
        tree_clear(i, j, rt, md + 1, b);
        T[x] = T[lt] + T[rt];
    }

    void flip(int i, int j) { tree_flip(i, j, 1, 0, n - 1); }

    void tree_flip(int i, int j, int x, int a, int b) {
        propagate(x, a, b);
        if (j < a || i > b) return;
        if (a == b) {
            T[x] = T[x] == 1 ? 0 : 1;
            return;
        }
        int lt = 2 * x, rt = lt + 1, md = (a + b) / 2;
        if (a >= i && b <= j) {
            T[x] = (b - a + 1) - T[x];
            U[lt] = apply_flip(U[lt]);
            U[rt] = apply_flip(U[rt]);
            return;
        }
        tree_flip(i, j, lt, a, md);
        tree_flip(i, j, rt, md + 1, b);
        T[x] = T[lt] + T[rt];
    }

    int query(int i, int j) { return tree_query(i, j, 1, 0, n - 1); }

    int tree_query(int i, int j, int x, int a, int b) {
        if (j < a || i > b) return -1;
        propagate(x, a, b);
	// don't check his babies if he is already in range
	// e.g. we want find i = 10, j = 20. if a = 12, b = 15, we can use this value
	// and don't need check his babies: 12-13, 14-15. 
        if (a >= i && b <= j) return T[x];
        int lt = 2 * x, rt = lt + 1, md = (a + b) / 2;
        int q1 = tree_query(i, j, lt, a, md);
        int q2 = tree_query(i, j, rt, md + 1, b);
        if (q1 < 0) return q2;
        if (q2 < 0) return q1;
        return q1 + q2;
    }

    int apply_flip(int v) {
        if (v == UP_SET) return UP_CLR;
        if (v == UP_CLR) return UP_SET;
        if (v == UP_FLP) return 0;
        return UP_FLP;
    }

    // propagate the lazy states ONCE to children
    // and U[x] = 0 so he's not lazy anymore
    void propagate(int x, int a, int b) {
        if (U[x] == 0) return;
        if (U[x] == UP_SET)
            T[x] = b - a + 1;
        else if (U[x] == UP_CLR)
            T[x] = 0;
        else if (U[x] == UP_FLP)
            T[x] = (b - a + 1) - T[x];

        if (a != b) {
            int lt = 2 * x, rt = lt + 1;
            if (U[x] == UP_SET || U[x] == UP_CLR)
                U[lt] = U[rt] = U[x];
            else
                U[lt] = apply_flip(U[lt]), U[rt] = apply_flip(U[rt]);
        }
        U[x] = 0;
    }
};

// hard qn. had to read other people's solution to learn how to do
// clear explanation https://lbv-pc.blogspot.com/2012/10/ahoy-pirates_24.html
// this level of code i think i need another 500 qn practice later to write myself with no template @_@

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i) {
        cout << "Case " << i << ":\n";
        int M;
        cin >> M;
        string pirates, s;
        while (M--) {
            int T;
            cin >> T;
            cin >> s;
            while (T--) pirates += s;
        }
        int N = pirates.size();
        SegTree st(N);
        for (int j = 0; j < N; ++j) st.A[j] = pirates[j] - '0';
        st.init();
        int Q;
        cin >> Q;
        int q = 1;
        while (Q--) {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'F') st.set(a, b);
            else if (c == 'E') st.clear(a, b);
            else if (c == 'I') st.flip(a, b);
            else cout << "Q" << q++ << ": " << st.query(a, b) << "\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




