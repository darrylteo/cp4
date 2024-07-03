#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 105; // adjust as needed
struct AugmentedMatrix { ld mat[MAX_N][MAX_N+1]; };
struct ColumnVector { ld vec[MAX_N]; };
ColumnVector GaussianElimination(int N, AugmentedMatrix Aug) {
// input: N, Augmented Matrix Aug, output: Column vector X, the answer
    for (int i = 0; i < N-1; ++i) { // forward elimination
        int l = i;
        for (int j = i+1; j < N; ++j) // row with max col value
            if (fabs(Aug.mat[j][i]) > fabs(Aug.mat[l][i]))
                l = j; // remember this row l
// swap this pivot row, reason: minimize floating point error
        for (int k = i; k <= N; ++k)
            swap(Aug.mat[i][k], Aug.mat[l][k]);
        for (int j = i+1; j < N; ++j) // actual fwd elimination
            for (int k = N; k >= i; --k) {
                Aug.mat[j][k] -= Aug.mat[i][k] * Aug.mat[j][i] / Aug.mat[i][i];
            }
    }
    ColumnVector Ans; // back substitution phase
    for (int j = N-1; j >= 0; --j) { // start from back
        ld t = 0.0;
        for (int k = j+1; k < N; ++k)
            t += Aug.mat[j][k] * Ans.vec[k];
        Ans.vec[j] = (Aug.mat[j][N]-t) / Aug.mat[j][j]; // the answer is here
    }
    return Ans;
}

// 0 = ok. 1 = inconsistent. 2 = infinite solutions
int property(int N, AugmentedMatrix Aug) {
    // check when all left hand side (LHS) == 0
    for (int i = 0; i < N; ++i) { // for each eqn
        bool valid = false; // valid == false means no variables (LHS == 0)
        for (int j = 0; j < N; ++j) {
            if (fabs(Aug.mat[i][j]) > 1e-9) { // not zero
                valid = true;
                break;
            }
        }
        if (!valid) { // LHS == 0
            if (fabs(Aug.mat[i][N]) > 1e-9) return 1; // inconsistent RHS != 0
            else return 2; // infinite solutions RHS == 0 (also can say missing 1 variable)
        }
    }
    // check linearly dependent
    for (int i = 0; i < N; ++i) { // eqn1
        for (int j = i + 1; j < N; ++j) { // compare against all other rows (at most 100C2)
            vector<ld> ratio;
            bool dep = true;

            for (int k = 0; k < N; k++) {
                if (fabs(Aug.mat[i][k]) != 0 && fabs(Aug.mat[j][k]) != 0) { // have ratio to consider
                    if (ratio.empty()) {
                        ratio.push_back(Aug.mat[i][k] / Aug.mat[j][k]);
                    } else {
                        if (fabs(ratio.back() - Aug.mat[i][k] / Aug.mat[j][k]) > 1e-9) {
                            dep = false;
                            break;
                        }
                    }
                } else if (fabs(Aug.mat[i][k]) > 1e-9 || fabs(Aug.mat[j][k]) > 1e-9) { // 1 zero 1 not zero
                    dep = false;
                    break;
                }
            }

            if (dep) {
                if (fabs(Aug.mat[i][N] / Aug.mat[j][N] - ratio[0]) > 1e-9) return 1; // linearly dependent but wrong rhs ratio
                else return 2; // really linearly dependent
            }
        }
    }
    return 0; // ok
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
        for (int i = 0; i < N; ++i) {
            cin >> Aug.mat[i][N];
        }
        int prop = property(N, Aug);
        if (prop == 1) {
            cout << "inconsistent" << endl;
        } else if (prop == 2) {
            cout << "multiple" << endl;
        } else {
            ColumnVector Ans = GaussianElimination(N, Aug);
            for (int i = 0; i < N; ++i) {
                cout << fixed << setprecision(8) << Ans.vec[i] << ' ';
            }
            cout << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
