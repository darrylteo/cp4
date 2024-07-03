#include <bits/stdc++.h>

using namespace std;

string cards[5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    for (int i = 0; i < 5; i++) {
        cin >> cards[i];
    }
    sort(cards, cards + 5);
    int maxCnt = 1, cnt = 1;
    for (int i = 0; i < 4; ++i) {
        if (cards[i][0] == cards[i + 1][0]) {
            cnt++;
            maxCnt = max(maxCnt, cnt);
        } else {
            cnt = 1;
        }
    }
    printf("%d\n", maxCnt);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}