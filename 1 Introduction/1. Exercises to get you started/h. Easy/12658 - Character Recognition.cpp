#include <bits/stdc++.h>

using namespace std;

int n;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &n);
    int a[n];
    char l[100];
    // go to line 4
    for (int i = 0; i < 4; i++) scanf("%s", l);
    for (int i = 0; i < 4*n; i++) {
        if (l[i] == '*'){
            if (i % 4 == 1) a[i/4] = 1;
            else if (i % 4 == 0) a[i/4] = 2;
            else if (i % 4 == 2) a[i/4] = 3;
        }
    }

    for (int i = 0; i < n; i++) printf("%d", a[i]);
    printf("\n");

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}