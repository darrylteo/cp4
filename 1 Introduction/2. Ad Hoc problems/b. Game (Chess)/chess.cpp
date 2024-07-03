#include <bits/stdc++.h>

using namespace std;

int T;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> T;
    while (T--) {
        char X1, Y1;
        int X2, Y2;
        cin >> X1 >> X2 >> Y1 >> Y2;

        // if X is odd, Y is even, or vice versa, output impossible
        if ((X1 + X2) % 2 == 1 && (Y1 + Y2) % 2 == 0 || (X1 + X2) % 2 == 0 && (Y1 + Y2) % 2 == 1) {
            cout << "Impossible" << endl;
        } else if (X1 == Y1 && X2 == Y2) { // if X == Y, output 0
            printf("0 %c %d\n", X1, X2);
        } else {
            // if X and Y are on the same diagonal, output 1
            if (abs(X1 - Y1) == abs(X2 - Y2)) { // using run == rise
                printf("1 %c %d %c %d\n", X1, X2, Y1, Y2);
            } else { // if X and Y are on different diagonals, output 2
                // go to intermediate point

                int flag = 0;
                if (flag == 0) {
                    for (int k = -8; k <= 8; k++) { // +1 slope
                        if (abs(X1 + k - Y1) == abs(X2 + k - Y2) && (X1 + k >= 'A' && X1 + k <= 'H') && (X2 + k >= 1 && X2 + k <= 8)) {
                            printf("2 %c %d %c %d %c %d\n", X1, X2, X1 + k, X2 + k, Y1, Y2);
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag == 0) {
                    for (int k = -8; k <= 8; k++) { // -1 slope
                        if (abs(X1 - k - Y1) == abs(X2 + k - Y2) && (X1 - k >= 'A' && X1 - k <= 'H') && (X2 + k >= 1 && X2 + k <= 8)) {
                            printf("2 %c %d %c %d %c %d\n", X1, X2, X1 - k, X2 + k, Y1, Y2);
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
