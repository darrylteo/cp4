#include <bits/stdc++.h>
using namespace std;

int X, Y, N;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %d %d", &X, &Y, &N);
    for (int i = 1; i <= N; i++) {
        if (i % X == 0 && i % Y == 0) {
            printf("FizzBuzz\n");
        } else if (i % X == 0) {
            printf("Fizz\n");
        } else if (i % Y == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}