#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;

const int MAX_N = 7;                             // adjust as needed
struct AugmentedMatrix {
    ld mat[MAX_N][MAX_N + 1];
};
struct ColumnVector {
    ld vec[MAX_N];
};

ColumnVector GaussianElimination(int N, AugmentedMatrix Aug) {
    // input: N, Augmented Matrix Aug, output: Column vector X, the answer
    for (int i = 0; i < N - 1; ++i) {                // forward elimination
        int l = i;
        for (int j = i + 1; j < N; ++j)                // row with max col value
            if (fabs(Aug.mat[j][i]) > fabs(Aug.mat[l][i]))
                l = j;                                   // remember this row l
        // swap this pivot row, reason: minimize floating point error
        for (int k = i; k <= N; ++k)
            swap(Aug.mat[i][k], Aug.mat[l][k]);
        for (int j = i + 1; j < N; ++j)                // actual fwd elimination
            for (int k = N; k >= i; --k)
                Aug.mat[j][k] -= Aug.mat[i][k] * Aug.mat[j][i] / Aug.mat[i][i];
    }

    ColumnVector Ans;                              // back substitution phase
    for (int j = N - 1; j >= 0; --j) {               // start from back
        ld t = 0.0;
        for (int k = j + 1; k < N; ++k) t += Aug.mat[j][k] * Ans.vec[k];
        Ans.vec[j] = (Aug.mat[j][N] - t) / Aug.mat[j][j]; // the answer is here
    }
    return Ans;
}

ull myPow(ull base, ull exp) {
    ull result = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}

// 1500 ^ 6 < 2 ^ 64 so ull is ok

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        AugmentedMatrix Aug;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                Aug.mat[i][j] = myPow(i + 1, j);
            }
        }
        for (int i = 0; i < 7; i++) {
            cin >> Aug.mat[i][7];
        }
        ColumnVector ans = GaussianElimination(7, Aug); // use this to check all remaining values
        // make all to unsigned long long
//        vector<ull> ansVec(7);
//        for (int i = 0; i < 7; i++) ansVec[i] = (ull) (ans.vec[i] + 1e-6);
        int bad = 0;
        for (int i = 8; i <= 1500; ++i) {
            ull sum = 0;
            ull val;
            cin >> val;
            for (int j = 0; j < 7; ++j) {
                sum += ans.vec[j] * myPow(i, j);
                if (sum > val) {
                    bad = 1;
                    break;
                }
            }
            if (sum != val) bad = 1;
        }

        // check if all 0<=ai<=1000
        for (ld i : ans.vec) {
            if (i < 0 || i > 1000) {
                bad = 1;
                break;
            }
        }

        if (bad) cout << "This is a smart sequence!\n";
        else {
            for (int i = 0; i < 7; i++) {
                cout << ans.vec[i];
                if (i < 6) cout << " ";
            }
            cout << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
