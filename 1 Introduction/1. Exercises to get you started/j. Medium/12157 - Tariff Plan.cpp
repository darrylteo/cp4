#include <bits/stdc++.h>

using namespace std;

int T, N;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d", &N);
        int mileCost = 0, juiceCost = 0;
        for (int j = 0; j < N; j++) {
            int call;
            scanf("%d", &call);
            mileCost += (call / 30 + 1) * 10;
            juiceCost += (call / 60 + 1) * 15;
        }
        if (mileCost < juiceCost) {
            printf("Case %d: Mile %d\n", i, mileCost);
        } else if (mileCost > juiceCost) {
            printf("Case %d: Juice %d\n", i, juiceCost);
        } else {
            printf("Case %d: Mile Juice %d\n", i, mileCost);
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

