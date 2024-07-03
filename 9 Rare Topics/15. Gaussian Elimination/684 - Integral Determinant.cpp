#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAX_N = 35;                             // adjust as needed
struct AugmentedMatrix {
    ld mat[MAX_N][MAX_N];
};
struct ColumnVector {
    ld vec[MAX_N];
};

ll GaussianElimination(int N, AugmentedMatrix Aug) {
    int cntSwap = 0;                                // count number of swaps
    // input: N, Augmented Matrix Aug, output: Column vector X, the answer
    for (int i = 0; i < N - 1; ++i) {                // forward elimination
        int l = i;
        for (int j = i + 1; j < N; ++j)                // row with max col value
            if (fabs(Aug.mat[j][i]) > fabs(Aug.mat[l][i]))
                l = j;                                   // remember this row l
        if (l != i) cntSwap++; // we swap, so determinant sign changes
        // swap this pivot row, reason: minimize floating point error
        for (int k = i; k <= N; ++k) {
            swap(Aug.mat[i][k], Aug.mat[l][k]);
        }
        for (int j = i + 1; j < N; ++j)                // actual fwd elimination
            for (int k = N; k >= i; --k) {
                if (fabs(Aug.mat[i][i]) < 1e-9) return 0; // determinant is 0
                Aug.mat[j][k] -= Aug.mat[i][k] * Aug.mat[j][i] / Aug.mat[i][i];
            }
    }

    // return determinant instead
    ld det = 1;
    for (int i = 0; i < N; ++i) det *= Aug.mat[i][i];
    if (cntSwap % 2) det = -det;                      // odd number of swaps
    return (ll) round(det); // playing with fire with round() :P
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    while (cin >> N, N) {
        AugmentedMatrix Aug;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> Aug.mat[i][j];
            }
        }

        ll det = GaussianElimination(N, Aug);
        cout << det << endl;
    }
    cout << "*\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
