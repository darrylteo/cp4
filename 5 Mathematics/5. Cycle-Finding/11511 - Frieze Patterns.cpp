#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// from sample input looks like it will repeat itself every n+1 cols

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, i, j;
    while (cin >> N >> i >> j, N) {
        vector<vector<ull>> grid(N, vector<ull>(N + 1)); // need to get to n+1 col to repeat
        for (int k = 0; k < N; ++k) cin >> grid[k][0]; // fill first col
        for (int k = 0; k <= N; ++k) grid[0][k] = grid[N - 1][k] = 1; // qn say first and last row are all 1
        for (int k = 1; k <= N; ++k) { // col k
            for (int l = 1; l < N - 1; ++l) { // row l
                grid[l][k] = (grid[l - 1][k] * grid[l + 1][k - 1] + 1) / grid[l][k - 1];
            }
        }
        j %= N + 1; // repeat every n+1 cols
        if (j == 0) j = N + 1; // don't want to go out of bounds
        cout << grid[i - 1][j - 1] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

