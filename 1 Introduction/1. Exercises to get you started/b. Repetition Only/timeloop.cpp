#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        printf("%d Abracadabra\n", i);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}