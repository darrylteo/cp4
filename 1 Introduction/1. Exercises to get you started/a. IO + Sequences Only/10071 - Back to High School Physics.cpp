#include <bits/stdc++.h>
using namespace std;

int v, t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d %d", &v, &t) != EOF){
        printf("%d\n", v*t*2);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}