#include <bits/stdc++.h>
using namespace std;

int T, N, curr;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++){
        int high = 0;
        scanf("%d", &N);
        while (N--){
            scanf("%d", &curr);
            if (curr > high)
                high = curr;
        }
        printf("Case %d: %d\n", t, high);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}