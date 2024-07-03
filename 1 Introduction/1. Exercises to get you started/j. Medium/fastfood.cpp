#include <bits/stdc++.h>

using namespace std;

int T, n, m, k, prizeArr[10][30] = {};

// the example is bad!!!
// the sticker numbers are not incrementing by 1 each time

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> k;
            prizeArr[i][0] = k;
            for (int j = 1; j <= k + 1; ++j) {
                cin >> prizeArr[i][j];
            }
        }

        int total = 0, stickers[100] = {};
        for (int i = 0; i < m; ++i) {
            cin >> stickers[i];
        }

        for (int prizeId = 0; prizeId < n; prizeId++) {
            int minPrizeI = INT_MAX;
            for (int i = 1; i <= prizeArr[prizeId][0]; ++i) {
                if (stickers[prizeArr[prizeId][i] - 1] < minPrizeI) {
                    minPrizeI = stickers[prizeArr[prizeId][i] - 1];
                }
            }
            total += minPrizeI * prizeArr[prizeId][prizeArr[prizeId][0] + 1];
        }
        cout << total << endl;

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

