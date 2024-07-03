#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int mod(int a, int n) { return (a % n + n) % n; }

int extEuclid(int a, int b, int &x, int &y) {  // pass x and y by ref
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {  // repeats until b == 0
        ll q = a / b;
        tie(a, b) = tuple(b, a % b);
        tie(x, xx) = tuple(xx, x - q * xx);
        tie(y, yy) = tuple(yy, y - q * yy);
    }
    return a;  // returns gcd(a, b)
}

int modInverse(int a, int n) {  // returns modular inverse of a mod n
    int x, y;
    extEuclid(a, n, x, y);
    return mod(x, n);
}

const int MAX_N = 75; // adjust as needed
// hmm seems like this qn everything will be integers
// risky but let's try
struct AugmentedMatrix {
    int mat[MAX_N][MAX_N + 1];
};
struct ColumnVector {
    int vec[MAX_N];
};

ColumnVector GaussianElimination(int N, AugmentedMatrix Aug, int p) {
// input: N, Augmented Matrix Aug, output: Column vector X, the answer
    for (int i = 0; i < N - 1; ++i) { // forward elimination
        int l = i;
        for (int j = i + 1; j < N; ++j) // row with max col value
            if (fabs(Aug.mat[j][i]) > fabs(Aug.mat[l][i]))
                l = j; // remember this row l
// swap this pivot row, reason: minimize floating point error
        for (int k = i; k <= N; ++k)
            swap(Aug.mat[i][k], Aug.mat[l][k]);
        for (int j = i + 1; j < N; ++j) // actual fwd elimination
            for (int k = N; k >= i; --k) {
                Aug.mat[j][k] -= mod(Aug.mat[i][k] * Aug.mat[j][i], p) * modInverse(Aug.mat[i][i], p);
                Aug.mat[j][k] = mod(Aug.mat[j][k], p);
            }
    }
    ColumnVector Ans; // back substitution phase
    for (int j = N - 1; j >= 0; --j) { // start from back
        int t = 0;
        for (int k = j + 1; k < N; ++k) {
            t += mod(Aug.mat[j][k] * Ans.vec[k], p);
            t = mod(t, p);
        }
        Ans.vec[j] = mod((Aug.mat[j][N] - t), p) * modInverse(Aug.mat[j][j], p);
        Ans.vec[j] = mod(Ans.vec[j], p);
    }
    return Ans;
}

// from sample input, first eqn is f(x) = 1 + 0x + 0x^2 MOD 31
// f(1) = 1, f(2) = 1, f(3) = 1. hence answer is aaa
// we can just reverse the function to get a set of linear eqns
// f(0) = 1 => a + b*1 + c*1^2 = 1
// f(1) = 1 => a + b*2 + c*2^2 = 1
// f(2) = 1 => a + b*3 + c*3^2 = 1
// and solve, with the mod.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int p;
        cin >> p;
        string s;
        cin >> s;
        int N = s.size();
        AugmentedMatrix Aug;
        // fill RHS
        for (int i = 0; i < N; ++i) {
            if (s[i] == '*') Aug.mat[i][N] = 0;
            else Aug.mat[i][N] = s[i] - 'a' + 1; // a = 1, b = 2, c = 3, ...
        }
        for (int i = 0; i < N; ++i) {
            Aug.mat[i][0] = 1; // column 0 is always 1
            for (int j = 1; j < N; ++j) {
                Aug.mat[i][j] = mod(Aug.mat[i][j - 1] * (i + 1), p);
            }
        }
        ColumnVector Ans = GaussianElimination(N, Aug, p);
        for (int i = 0; i < N; ++i) {
            cout << Ans.vec[i] << ' ';
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
