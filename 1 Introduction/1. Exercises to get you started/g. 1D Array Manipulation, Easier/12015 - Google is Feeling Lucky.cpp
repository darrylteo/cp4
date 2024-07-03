#include <bits/stdc++.h>

using namespace std;

int T, V[10];
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &T);
    for (int caseNo = 1; caseNo <= T; caseNo++){
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < 10; i++) scanf("%*s %d", &V[i]);
        int maxV = 0;
        char website[100];
        for (int i = 0; i < 10; i++) if (V[i] > maxV) maxV = V[i];
        rewind(stdin);
        for (int i = 0; i < (caseNo-1)*10+1; i++){
            scanf("%*s %*d");
        }
        for (int i = 0; i < 10; i++) {
            scanf("%s %d", website, &V[i]);
            if (V[i] == maxV) printf("%s\n", website);
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}