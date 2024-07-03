#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &a, &b);
        if (a > b){
            printf(">\n");
        } else if (a < b){
            printf("<\n");
        } else {
            printf("=\n");
        }
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}