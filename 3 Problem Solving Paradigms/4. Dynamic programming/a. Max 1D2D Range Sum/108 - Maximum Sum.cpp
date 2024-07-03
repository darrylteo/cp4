// Maximum Sum
// O(n^3) 1D DP + greedy (Kadane's) solution, 0.000s in UVa

#include <bits/stdc++.h>
using namespace std;

#define MAX_n 110

int A[MAX_n][MAX_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
    int n; scanf("%d", &n);                        // square matrix size
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]);
            if (j > 0) A[i][j] += A[i][j-1];           // pre-processing
        }
    int maxSubRect = -127*100*100;                 // lowest possible val
    for (int l = 0; l < n; ++l)
        for (int r = l; r < n; ++r) {
            int subRect = 0;
            for (int row = 0; row < n; ++row) {
                // Max 1D Range Sum on columns of this row
                if (l > 0) subRect += A[row][r] - A[row][l-1];
                else       subRect += A[row][r];
                // Kadane's algorithm on rows
                if (subRect < 0) subRect = 0;            // restart if negative
                maxSubRect = max(maxSubRect, subRect);
            }
        }
    printf("%d\n", maxSubRect);
    return 0;
}