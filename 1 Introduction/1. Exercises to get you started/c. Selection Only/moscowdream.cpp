#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
    
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    printf(((a >= 1) && (b >= 1) && (c >= 1) && (a+b+c >= n) && (n >= 3)) ? "YES\n" : "NO\n");
    return 0;
}