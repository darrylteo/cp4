#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while(scanf("%d %d", &x, &y), x||y){
        if (x + y == 13){
            printf("Never speak again.\n");
        } else if (x > y){
            printf("To the convention.\n");
        } else if (x < y){
                printf("Left beehind.\n");
        } else {
            printf("Undecided.\n");
        }

    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}