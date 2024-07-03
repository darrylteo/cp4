#include <bits/stdc++.h>

using namespace std;

int B, N, D, C, V;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d %d", &B, &N), B){
        int bank[B];
        for (int i = 0; i < B; i++) {
            scanf("%d", &bank[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &D, &C, &V);
            bank[D - 1] -= V;
            bank[C - 1] += V;
        }
        bool flag = true;
        for (int i = 0; i < B; i++) {
            if (bank[i] < 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}