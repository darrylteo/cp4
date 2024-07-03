#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    bool start = true;
    while (cin >> N, N) {
        if (!start) {
            printf("\n");
        }
        start = false;
        bool flag = false;
        for (int fghij = 1234; fghij <= 98765 / N; ++fghij) {
            int abcde = fghij * N; // as discussed above
            int tmp, used = (fghij < 10000); // flag if f = 0
            tmp = abcde;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if (used == (1 << 10) - 1) {
                flag = true;
                printf("%05d / %05d = %d\n", abcde, fghij, N);
            } // all 10 digits are used
        }
        if (!flag)
            printf("There are no solutions for %d.\n", N);

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
