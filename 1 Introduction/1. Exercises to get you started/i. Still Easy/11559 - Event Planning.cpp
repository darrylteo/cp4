#include <bits/stdc++.h>

using namespace std;

int N, B, H, W;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
        int p, a;
        int minCost = INT_MAX;
        for (int i = 0; i < H; i++) {
            scanf("%d", &p);
            for (int j = 0; j < W; j++) {
                scanf("%d", &a);
                if (a >= N && p * N <= B) {
                    minCost = min(minCost, p * N);
                }
            }
        }
        if (minCost == INT_MAX) {
            printf("stay home\n");
        } else {
            printf("%d\n", minCost);
        }
    }




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}