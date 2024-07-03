#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct State{
    ll mask;
    char step;
    bool operator<(const State &x) const {
        return mask < x.mask;
    }
    bool operator==(const State &x) const {
        return mask == x.mask;
    }
    inline void set(int p, ll val) {
        mask |= val << (p << 2);
    } // set the p-th bit to val. the p here is 'hexadecimal' bit position, so it uses 4 bits (<<2)
    inline ll get(int p) const {
        return (mask >> (p << 2)) & 0xf;
    } // get the p-th bit of mask. 0xf is a full 4-bit mask
    void print() {
        for (int i = 0; i < 12; ++i) {
            cout << get(i) + 1 << " ";
        }
        cout << "\n";
    }
};

struct StateHash {
    size_t operator()(const State &k) const {
        return k.mask;
    }
};

static State rotateV;

void lc(const State &u) {
    rotateV = u;
    rotateV.mask &= 0x0fffff000000LL;
    rotateV.mask |= 0x0000000fffffLL & (u.mask >> 4);
    rotateV.set(5, u.get(11));
    rotateV.set(11, u.get(0));
} // left clockwise. 0x0fffff000000LL means bits 10,9,8,7,6 stay the same. 0x0000000fffffLL & (u >> 4) means bits 5,4,3,2,1 become bits 4,3,2,1,0
void lcc(const State &u) {
    rotateV = u;
    rotateV.mask &= 0x0fffff000000LL;
    rotateV.mask |= 0x000000fffff0LL & (u.mask << 4);
    rotateV.set(0, u.get(11));
    rotateV.set(11, u.get(5));
} // left counter-clockwise. 0x0fffff000000LL means bits 10,9,8,7,6 stay the same. 0x000000fffff0LL & (u << 4) means bits 4,3,2,1,0 become bits 5,4,3,2,1
// in summary, the pos of 'f' are what the bits "become" after rotation and left shift means original bits are smaller pos. the rest no more explain
void rc(const State &u) {
    rotateV = u;
    rotateV.mask &= 0x0000000fffffLL;
    rotateV.mask |= 0x0ffffff00000LL & (u.mask >> 4);
    rotateV.set(11, u.get(5));
} // right clockwise
void rcc(const State &u) {
    rotateV = u;
    rotateV.mask &= 0x0000000fffffLL;
    rotateV.mask |= 0xffffff000000LL & (u.mask << 4);
    rotateV.set(5, u.get(11));
} // right counter-clockwise
void wc(const State &u) {
    rotateV.mask = 0x0fffffffffffLL & (u.mask >> 4);
    rotateV.set(11, u.get(0));
} // whole clockwise
void wcc(const State &u) {
    rotateV.mask = 0xfffffffffff0LL & (u.mask << 4);
    rotateV.set(0, u.get(11));
} // whole counter-clockwise

void (*f[])(const State &) = {lc, lcc, rc, rcc, wc, wcc}; // funky array of function pointers

// standard bfs just until halfway (9 steps)
unordered_set<State, StateHash> R;
static State q[3215101 + 10];
void init() {
    State st;
    st.mask = 0, st.step = 0;
    for (int i = 0; i < 12; ++i) {
        st.mask |= (ll) i << ((ll) i << 2);
    } // 0,2,3,...,11
    R.insert(st);
    q[0] = st;
    // funky check if queue empty... qidx will stop increasing once step 9 is reached and terminate this loop
    for (int i = 0, qidx = 1; i < qidx; ++i) {
        st = q[i];
        for (int j = 0; j < 6; ++j) {
            f[j](st);
            State t = rotateV;
            t.step = st.step + 1;
            bool inq = R.insert(t).second;
            if (inq && t.step < 10) {
                q[qidx] = t;
                ++qidx;
            }
        }
    }
}

int bfs(const int v[]) {
    State st;
    st.mask = 0, st.step = 1;
    for (int i = 0; i < 12; ++i) {
        st.mask |= (ll) v[i] << ((ll) i << 2);
    } // set according to current query
    auto it = R.find(st);
    if (it != R.end()) {
        return it->step;
    }
    unordered_set<State, StateHash> R2;
    R2.insert(st);
    q[0] = st;
    for (int i = 0, qidx = 1; i < qidx; ++i) {
        st = q[i];
        for (int j = 0; j < 6; ++j) {
            f[j](st);
            State t = rotateV;
            t.step = st.step + 1;
            it = R.find(t);
            if (it != R.end()) {
                return it->step + st.step;
            }
            bool inq = R2.insert(t).second;
            if (inq && t.step < 10) {
                q[qidx] = t;
                ++qidx;
            }
        }
    }
    return -1;
}

// crazy difficult qn. ref: https://github.com/morris821028/UVa/blob/master/volume124/12445%20-%20Happy%2012.cpp
// interesting idea to use hexadecimal as "bitset"

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int v[12];
        for (int i = 0; i < 12; ++i) {
            cin >> v[i];
            --v[i];
        }
        int ret = bfs(v);
        if (ret == -1) {
            cout << 19 << '\n';
        } else {
            cout << ret << "\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}