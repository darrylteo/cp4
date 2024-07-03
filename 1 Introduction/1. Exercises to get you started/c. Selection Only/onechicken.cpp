#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %d", &N, &M);
    if (M > N) {
        printf("Dr. Chaz will have %d piece%s of chicken left over!", M - N, (M - N) > 1 ? "s" : "");
    } else {
        printf("Dr. Chaz needs %d more piece%s of chicken!", N - M, (N - M) > 1 ? "s" : "");
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}