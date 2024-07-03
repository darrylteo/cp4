#include <bits/stdc++.h>
using namespace std;

long long n1, n2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%lld %lld", &n1, &n2) != EOF) {
        printf("%lld\n", abs(n1-n2));
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}