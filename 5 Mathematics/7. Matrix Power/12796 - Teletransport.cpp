#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD;
const int MAX_N = 101; // 2x2 for Fib matrix
struct Matrix {
    ll mat[MAX_N][MAX_N];
}; // we return a 2D array

Matrix matMul(Matrix a, Matrix b) {              // normally O(n^3)
    Matrix ans;                                    // but O(1) as n = 2
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            ans.mat[i][j] = 0;
    for (int i = 0; i < MAX_N; ++i)
        for (int k = 0; k < MAX_N; ++k) {
            if (a.mat[i][k] == 0) continue;            // optimization
            for (int j = 0; j < MAX_N; ++j) {
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                ans.mat[i][j] %= MOD; // modular arithmetic
            }
        }
    return ans;
}

Matrix matPow(Matrix base, int p) { // normally O(n^3 log p)
    Matrix ans; // but O(log p) as n = 2
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            ans.mat[i][j] = (i == j); // prepare identity matrix
    while (p) { // iterative D&C version
        if (p & 1) // check if p is odd
            ans = matMul(ans, base); // update ans
        base = matMul(base, base); // square the base
        p >>= 1; // divide p by 2
    }
    return ans;
}

// applying directly from book where they say matrix power gives number of paths of length L
// we do 1 based indexing here

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L, S, T;
    while (cin >> N >> L >> S >> T) {
        Matrix base{};
        int x;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> x;
                base.mat[i][x]++;
            }
        }
        MOD = 10000;
        Matrix res = matPow(base, L);
        cout << res.mat[S][T] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

