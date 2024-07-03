#include <bits/stdc++.h>

using namespace std;

const int MAX_MOVE_COUNT = 100;
const int ROW_SIZE = 4; // 4 columns
int best;
int COL_SIZE;
int PUZZLE;
vector<int> p;
int blank;
int lim;
int dr[] = {0, -1, 0, 1}; // E,N,W,S
int dc[] = {1, 0, -1, 0}; // R,U,L,D
int pred[MAX_MOVE_COUNT + 1];

int dist(int r1, int r2, int c1, int c2) {
    int ret = abs(r1 - r2); // row no wrapping
    if (abs(c1 - c2) == 3) ret += 1; // column wrapping
    else ret += abs(c1 - c2); // column no wrapping
    return ret;
}

inline int h1() { // heuristic: sum of Manhattan distances (compute all)
    int ans = 0;
    for (int i = 0; i < PUZZLE; i++) {
        if (p[i] == 0) continue; // king at 0
        int r1 = i / ROW_SIZE;
        int c1 = i % ROW_SIZE;
        int r2 = p[i] / ROW_SIZE;
        int c2 = p[i] % ROW_SIZE;
        ans += dist(r1, r2, c1, c2);
    }
    return ans;
}

// heuristic: sum of manhattan distances (compute delta)
// remove old val, add new val
inline int h2(int i1, int j1, int i2, int j2) {
    int tgt_i = p[i2 * ROW_SIZE + j2] / ROW_SIZE, tgt_j = p[i2 * ROW_SIZE + j2] % ROW_SIZE;
    return -dist(i2, tgt_i, j2, tgt_j) + dist(i1, tgt_i, j1, tgt_j);
}

// pretty much same as before. just allow wrap around
// if draw out how the king can jump, we see the king jump is up down left right in 4 column grid
bool DFS(int g, int h, int k) {
    if (g + h > lim) return false;

    if (h == 0) {
        best = g;
        return true;
    }

    int i, j, d, new_i, new_j;
    i = k / ROW_SIZE;
    j = k % ROW_SIZE;

    for (d = 0; d < 4; d++) {
        if (g != 0 && d == (pred[g] ^ 2)) continue;
        new_i = i + dr[d];
        new_j = (j + dc[d] + ROW_SIZE) % ROW_SIZE;
        if (new_i >= 0 && new_i < COL_SIZE) {
            int new_k = new_i * ROW_SIZE + new_j;
            int dh = h2(i, j, new_i, new_j);
            swap(p[k], p[new_k]); // swap first
            pred[g + 1] = d;
            if (DFS(g + 1, h + dh, new_k)) return true; // if ok, no need to restore, just go ahead
            swap(p[k], p[new_k]); // restore
        }
    }

    return false;
}

int IDA_Star() {
    lim = h1();
    while (lim <= MAX_MOVE_COUNT) { // pruning condition in the problem
        if (DFS(0, h1(), blank)) return lim;
        lim++;
    }
    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, tc = 1;
    while (cin >> N, N) {
        int i, j, sum = 0, ans = 0;
        COL_SIZE = N / 4;
        PUZZLE = N;
        // from new formation in input, we have to make it to 1 2 3 4 5 ... N
        p.resize(PUZZLE);
        for (i = 0; i < PUZZLE; i++) {
            cin >> p[i];
            if (p[i] == 1) {
                blank = i; // remember the index of the king
            }
            p[i]--; // use 0-based indexing
        }

        IDA_Star();
        cout << "Set " << tc++ << ":\n";
        cout << best << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
