#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD;
const int MAX_N = 2; // 2x2 for Fib matrix
struct Matrix {
    ll mat[MAX_N][MAX_N];
}; // we return a 2D array

Matrix matMul(Matrix a, Matrix b) {              // normally O(n^3)
    Matrix ans{};
    for (int i = 0; i < MAX_N; ++i)
        for (int k = 0; k < MAX_N; ++k) {
            if (a.mat[i][k] == 0) continue;            // optimization
            for (int j = 0; j < MAX_N; ++j) {
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                ans.mat[i][j] %= MOD; // modulo arithmetic
            }
        }
    return ans;
}

Matrix matPow(Matrix base, ll p) { // normally O(n^3 log p)
    Matrix ans{}; // but O(log p) as n = 2
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

// direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll cases, n;
        cin >> cases >> n;
        Matrix base{};
        base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1;
        base.mat[1][1] = 0;
        MOD = 1000000000;
        Matrix ans = matPow(base, n);
        cout << cases << " " << ans.mat[0][1] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

