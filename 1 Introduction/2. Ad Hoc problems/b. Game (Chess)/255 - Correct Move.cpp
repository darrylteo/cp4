#include <bits/stdc++.h>

using namespace std;

int K, Q, newQ;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d %d %d", &K, &Q, &newQ) != EOF) {
        int rowK = K / 8, colK = K % 8;
        int rowQ = Q / 8, colQ = Q % 8;
        int newRowQ = newQ / 8, newColQ = newQ % 8;
        if (K == Q) {
            printf("Illegal state\n");
        } else if (K == newQ || Q == newQ) {
            printf("Illegal move\n");
        } else if (rowQ != newRowQ && colQ != newColQ) { // not in same row or column
            printf("Illegal move\n");
        } else if (newColQ == colK && newColQ == colQ &&
                   ((Q < K && K < newQ) || (Q > K && K > newQ))) { // both Q, K and new Q in same col and go above it
            printf("Illegal move\n");
        } else if (newRowQ == rowK && newRowQ == rowQ &&
                   ((Q < K && K < newQ) || (Q > K && K > newQ))) { // both Q, K and new Q in same row and go across it
            printf("Illegal move\n");
        } else if ((newRowQ == rowK - 1 && newColQ == colK) || (newRowQ == rowK + 1 && newColQ == colK) ||
                   (newRowQ == rowK && newColQ == colK - 1) ||
                   (newRowQ == rowK && newColQ == colK + 1)) { // one step away from king
            printf("Move not allowed\n");
        } else if ((K == 0 && newQ == 9) || (K == 7 && newQ == 14) || (K == 56 && newQ == 49) ||
                   (K == 63 && newQ == 54)) { // king at corner
            printf("Stop\n");
        } else {
            printf("Continue\n");
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


