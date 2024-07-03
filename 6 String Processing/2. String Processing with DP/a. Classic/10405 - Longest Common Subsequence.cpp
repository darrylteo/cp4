#include <bits/stdc++.h>

using namespace std;

int table[1005][1005]; // DP table

// copy paste from book code

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string A, B;
    while (getline(cin, A) && getline(cin, B)) {
        int n = (int) A.size(), m = (int) B.size();
        int i, j; // Needleman Wunsnch's algorithm

        memset(table, 0, sizeof table);

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                // match = 1 points, mismatch = -1e9 point
                table[i][j] =
                        table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 1 : -1000000000); // cost for match or mismatches
                // insert/delete = 0 point
                table[i][j] = max(table[i][j], table[i - 1][j]); // delete
                table[i][j] = max(table[i][j], table[i][j - 1]); // insert
            }
        }
        cout << table[n][m] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}