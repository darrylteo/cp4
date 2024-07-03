#include <bits/stdc++.h>

using namespace std;

// can either do the cumsum method or compress all into 1 dimension method. gfg uses compress method
// ref: https://www.geeksforgeeks.org/3d-kadanes-algorithm/
// very fast: same time as fastest soln 0.01s

typedef long long ll;

int M, N, O;
ll matrix[25][25][25], best;

void solve(){
    for (int i = 0; i < M; ++i) { // i: start of dimension 1
        ll tmp[30][30]; // compress once
        memset(tmp, 0, sizeof(tmp));
        for (int j = i; j < M; ++j) { // j: end of dimension 1
            for (int k = 0; k < N; ++k) { // k: dimension 2
                for (int l = 0; l < O; ++l) { // l: dimension 3
                    tmp[k][l] += matrix[j][k][l]; // collect everything from i to j
                }
            }
            for (int k = 0; k < N; ++k) { // k: start of dimension 2
                ll tmp2[30];
                memset(tmp2, 0, sizeof(tmp2));
                for (int l = k; l < N; ++l) { // l: end of dimension 2
                    ll sum = 0;
                    for (int m = 0; m < O; ++m) { // m: dimension 3
                        tmp2[m] += tmp[l][m]; // collect everything from k to l
                        sum += tmp2[m];
                        best = max(best, sum);
                        if (sum < 0) sum = 0;
                    }
                }
            }
        }
    }
    cout << best << "\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        memset(matrix, 0, sizeof(matrix));
        best = -(1LL << 62);
        cin >> M >> N >> O;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < O; ++k) {
                    cin >> matrix[i][j][k];
                }
            }
        }
        solve();
        if (n) cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
