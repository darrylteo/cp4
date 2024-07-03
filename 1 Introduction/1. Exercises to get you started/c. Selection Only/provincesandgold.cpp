#include <bits/stdc++.h>
using namespace std;

int G, S, C;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %d %d", &G, &S, &C);
    int total = G * 3 + S * 2 + C * 1;
    if (total >= 8) {
        printf("Province or ");
    } else if (total >= 5) {
        printf("Duchy or ");
    } else if (total >= 2) {
        printf("Estate or ");
    }
    if (total >= 6) {
        printf("Gold\n");
    } else if (total >= 3) {
        printf("Silver\n");
    } else {
        printf("Copper\n");
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}