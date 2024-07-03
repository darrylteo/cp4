#include <bits/stdc++.h>

using namespace std;

int n;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    printf("1 ");
    scanf("%d", &n);
    int d[n];
    for (int i = 0; i < n - 1; i++) {
        (scanf("%d", &d[i]), d);
    }
    // i is the number we are searching for, from smallest to largest
    // j is the index of the number in the given array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (d[j] == i) {
                printf("%d ", j + 2);
            }
        }
    }




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}