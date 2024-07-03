#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &x);
    scanf("%d", &y);
    if (x >= 0 && y >= 0)
        printf("1\n");
    else if (x <= 0 && y >= 0)
        printf("2\n");
    else if (x <= 0 && y <= 0)
        printf("3\n");
    else if (x >= 0 && y <= 0)
        printf("4\n");


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}