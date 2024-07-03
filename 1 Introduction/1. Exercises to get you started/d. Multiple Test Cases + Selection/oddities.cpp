#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &n);
    while (n--){
        scanf("%d", &x);
        printf("%d is %s\n", x, x % 2 == 0 ? "even" : "odd");
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}