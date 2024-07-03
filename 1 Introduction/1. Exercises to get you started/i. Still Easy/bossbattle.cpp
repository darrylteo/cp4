#include <bits/stdc++.h>

using namespace std;

int n;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // everytime u throw a bomb, eliminate 3 pillars, but boss can move to adjacent 2 pillars
    // i.e. every round n=n-3+2 until n=0. rmb edge cases n<4.
    scanf("%d", &n);
    if (n < 4) printf("1\n");
    else printf("%d\n", n-2);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}