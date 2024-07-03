#include <bits/stdc++.h>
using namespace std;

int X, N, P = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &X);
    scanf("%d", &N);
    int nPlusOne = N+1, Px;
    while (N--) {
        scanf("%d", &Px);
        P += Px;
    }
    printf("%d\n", X * (nPlusOne) - P);

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}