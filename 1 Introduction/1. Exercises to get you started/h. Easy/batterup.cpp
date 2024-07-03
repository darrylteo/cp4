#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &n);
    double cnt = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x == -1) {
            continue;
        } else {
            sum += x;
            cnt++;
        }
    }
    printf("%f\n", sum/cnt);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}