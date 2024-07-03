#include <bits/stdc++.h>
using namespace std;

int N;
long long n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &n);
        printf("%d\n", static_cast<int>(floor((-1+sqrt(1+8*n)) / 2)));
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}