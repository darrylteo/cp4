#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    int rank = 25, stars = 0, streak = 0;
    string s;
    cin >> s;
    for (char i: s) {
        if (i == 'W') {
            streak++;

            // add either 1 or 2 star only
            if (streak >= 3 && rank >= 6) {
                stars += 2;
            } else {
                stars++;
            }

            // rank up has multiple cases
            if (rank == 0) {
                cout << "Legend" << endl;
                return 0; // function breaker
            } else if (rank >= 21 && stars > 2) {
                rank--;
                stars -= 2;
            } else if (rank >= 16 && stars > 3) {
                rank--;
                stars -= 3;
            } else if (rank >= 11 && stars > 4) {
                rank--;
                stars -= 4;
            } else if (rank >= 1 && stars > 5) {
                rank--;
                stars -= 5;
            }

            // quite complicated for losses
        } else {
            streak = 0;

            // if legend then lose, nothing happen
            if (rank == 0) {
                continue;
            }
            // if rank is 20 or above, cannot lose rank, but rank 20 can lose star
            if (rank >= 21) {
                continue;
            } else if (rank == 20) {
                if (stars > 0) {
                    stars--;
                }
                continue;
            } else if (stars == 0) { // if no star, lose rank
                rank++;
                if (rank >= 16) {
                    stars = 2;
                } else if (rank >= 11) {
                    stars = 3;
                } else {
                    stars = 4;
                }
            } else {
                stars--;
            }
        }
    }

    if (rank == 0) {
        cout << "Legend" << endl;
    } else {
        cout << rank << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

