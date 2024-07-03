#include <bits/stdc++.h>
using namespace std;

int T, L, W, H;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &L, &W, &H);
        printf("Case %d: ", t);
        if (L <= 20 && W <= 20 && H <= 20) {
            printf("good\n");
        } else {
            printf("bad\n");
        }
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}