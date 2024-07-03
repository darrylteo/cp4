#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", static_cast<int>(abs((n*567/9+7492)*235/47-498)%100/10));
    }
    // modulo is weird for negative numbers, so use abs.
    // %100/10 OR /10%10 also ok to obtain digit in tens place.

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}