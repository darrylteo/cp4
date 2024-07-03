// Another n-Queen Problem

#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;

int n, mask[32];

ll bf(int row, int col, int left_diagonal, int right_diagonal) {
    if (row == n) return 1; // done, 1 way found
    // bit = all possible column positions
    int bit = mask[row] | col | left_diagonal | right_diagonal; // list of forbidden column
    bit = ~bit; // after negation, list of allowed columns, but it turns on more bits than necessary
    bit &= (1<<n) - 1; // (1<<n) - 1, turn on n bits only, we want to concentrate on these n bits only
    ll total = 0; // now recursively count the ways
    while (bit) { // try each bit that is turned on
        int t = LSOne(bit); // the first bit that is on
        // for future iterations, forbid column t and left_diagonal/right diagonal that has t
        total += bf(row+1, col | t, (left_diagonal|t) >> 1, (right_diagonal|t) << 1);
        bit -= t; // remove that bit t from 'bit'
    }
    return total;
}

// repeat of 11195 - Another n-Queen Problem

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    char M[32];
    while (scanf("%d ", &n), n) {
        int m;
        scanf("%d ", &m);
        memset(mask, 0, sizeof mask);
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d %d ", &x, &y);
            mask[x] |= 1 << y;
        }
        printf("%lld\n", bf(0, 0, 0, 0));
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}