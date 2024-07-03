#include <bits/stdc++.h>
using namespace std;

int X, Y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %d", &X, &Y);
    if (Y == 1){
        if (X == 0) printf("ALL GOOD\n");
        else printf("IMPOSSIBLE\n");
    } else {
        printf("%f\n", (double)X / (1 - Y));
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}