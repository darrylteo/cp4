#include <bits/stdc++.h>

using namespace std;

int t;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &t);
    double length, width, depth, weight;
    int noAllowed = 0;
    while (t--) {
        scanf("%lf %lf %lf %lf", &length, &width, &depth, &weight);
        if (((length <= 56.00 && width <= 45.00 && depth <= 25.00) || (length + width + depth <= 125.00)) &&
            weight <= 7.00) {
            noAllowed++;
            printf("1\n");
        } else
            printf("0\n");
    }
    printf("%d\n", noAllowed);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}