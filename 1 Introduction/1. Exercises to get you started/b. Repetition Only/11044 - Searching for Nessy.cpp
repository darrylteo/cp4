#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", static_cast<int>(floor(n/3) * floor(m/3)));
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}