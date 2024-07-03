#include <bits/stdc++.h>
using namespace std;

int p, a, b, c, d, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    double maxDrop = 0, maxScore = 0;
    for (int i = 1; i <= n; i++){
        double price = p*(sin(a*i + b) + cos(c*i + d) + 2);
        if (price > maxScore){
            maxScore = price;
        }
        if (maxScore - price > maxDrop){
            maxDrop = maxScore - price;
        }
    }
    printf("%lf\n", maxDrop);

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

// very slow... probably abstracting out the trigo functions would speed up