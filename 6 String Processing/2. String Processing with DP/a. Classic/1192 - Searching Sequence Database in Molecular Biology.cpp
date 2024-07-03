#include <bits/stdc++.h>

using namespace std;

// another direct application

int table[1005][1005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string A, B;
    vector<string> bestStrs;
    int bestVal = 0;
    cin >> A >> A;
    while (cin >> B >> B) {
        int n = (int) A.size(), m = (int) B.size();
        int i, j; // Needleman Wunsnch's algorithm

        memset(table, 0, sizeof table);
        // insert/delete = -7 point
        for (i = 1; i <= n; i++)
            table[i][0] = i * -7;
        for (j = 1; j <= m; j++)
            table[0][j] = j * -7;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++) {
                // match = 5 points, mismatch = -4 point
                table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 5 : -4); // cost for match or mismatches
                // insert/delete = -7 point
                table[i][j] = max(table[i][j], table[i - 1][j] - 7); // delete
                table[i][j] = max(table[i][j], table[i][j - 1] - 7); // insert
            }

        int ans = table[n][m];
        if (ans > bestVal) {
            bestVal = ans;
            bestStrs.clear();
            bestStrs.push_back(B);
        } else if (ans == bestVal) {
            bestStrs.push_back(B);
        }
    }

    cout << "The query sequence is:\n" << A << "\n\n";
    cout << "The most similar sequences are:\n\n";
    int first = 1;
    for (auto &s : bestStrs) {
        if (first) first = 0;
        else cout << "\n";
        cout << s << "\n";
        cout << "The similarity score is: " << bestVal << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}