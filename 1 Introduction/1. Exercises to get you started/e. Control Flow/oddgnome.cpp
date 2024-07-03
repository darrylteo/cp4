#include <bits/stdc++.h>
using namespace std;

int n, g, prevGnome, currGnome;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &n);
    while (n--){
        scanf("%d", &g);
        scanf("%d", &prevGnome);
        for (int i = 2; i <= g; i++){
            scanf("%d", &currGnome);
            if (currGnome != prevGnome + 1){
                printf("%d\n", i);
                // discard remainder of line (input)
                while (i < g){
                    scanf("%*d");
                    i++;
                }
            }
            prevGnome = currGnome;
        }
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}