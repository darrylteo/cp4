#include <bits/stdc++.h>

using namespace std;

// another direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T >> ws;
    while (T--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);
        int n = (int) A.size(), m = (int) B.size();
        int i, j, table[105][105]; // Needleman Wunsnch's algorithm

        memset(table, 0, sizeof table);
        // insert/delete = -1 point
        for (i = 1; i <= n; i++)
            table[i][0] = i * -1;
        for (j = 1; j <= m; j++)
            table[0][j] = j * -1;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++) {
                // match = 2 points, mismatch = -1 point
                table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 0 : -1); // cost for match or mismatches
                // insert/delete = -1 point
                table[i][j] = max(table[i][j], table[i - 1][j] - 1); // delete
                table[i][j] = max(table[i][j], table[i][j - 1] - 1); // insert
            }

        cout << -table[n][m] << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}