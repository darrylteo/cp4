#include <bits/stdc++.h>

using namespace std;

// concept difficult, code easy
// first col will be processed in order (obvious)
// first row will be processed in order (not so obvious)
// this is because other swathers will be dependent on the first row to complete their task M
// e.g. swather1 job2 takes very long, no matter how short s2j1 s2j1 are, still need wait s1j2 finish
// recursing down, each swather and job is the max of its previous job completion time or swather-1 complete

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N, M;
    cin >> N >> M;
    int flowShop[N][M];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> flowShop[i][j];
        }
    }

    // first col in order
    for (int j = 1; j < M; ++j) {
        flowShop[0][j] += flowShop[0][j - 1];
    }
    // first row in order
    for (int i = 1; i < N; ++i) {
        flowShop[i][0] += flowShop[i - 1][0];
    }

    // recurse either its own time or swather above time
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
         flowShop[i][j] += max(flowShop[i-1][j], flowShop[i][j-1]);
        }
    }

    // print for each swather
    for (int i = 0; i < N; ++i) {
        cout << flowShop[i][M-1] << " ";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
