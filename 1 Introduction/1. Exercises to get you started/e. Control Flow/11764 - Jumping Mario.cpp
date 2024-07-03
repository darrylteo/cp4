#include <bits/stdc++.h>
using namespace std;

int T, N, preve, curr;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++){
        int high = 0, low = 0;
        scanf("%d", &N);
        scanf("%d", &preve);
        for (int i = 2; i <= N; i++){
            scanf("%d", &curr);
            if (curr > preve){
                high++;
            } else if (curr < preve){
                low++;
            } else {}
            preve = curr;
        }
        printf("Case %d: %d %d\n", t, high, low);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}