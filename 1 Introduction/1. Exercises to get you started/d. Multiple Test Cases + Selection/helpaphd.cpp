#include <bits/stdc++.h>
using namespace std;

int N;
char problem[10];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);
    while (N--){
        scanf("%s", &problem);
        if (problem[0] == 'P'){
            printf("skipped\n");
        } else {
            int a, b;
            sscanf(problem, "%d+%d", &a, &b);
            printf("%d\n", a + b);
        }
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}