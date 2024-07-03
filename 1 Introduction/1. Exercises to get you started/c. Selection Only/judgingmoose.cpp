#include <bits/stdc++.h>
using namespace std;

int l, r;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %d", &l, &r);
    if (l == 0 && r == 0) {
        printf("Not a moose\n");
    } else if (l == r) {
        printf("Even %d\n", l + r);
    } else {
        printf("Odd %d\n", max(l, r) * 2);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}