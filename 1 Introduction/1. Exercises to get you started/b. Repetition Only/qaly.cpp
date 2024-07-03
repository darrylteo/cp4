#include <bits/stdc++.h>
using namespace std;

int N;
float q, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    float qaly = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%f %f", &q, &y);
        qaly += q*y;
    }
    printf("%f\n", qaly);

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}