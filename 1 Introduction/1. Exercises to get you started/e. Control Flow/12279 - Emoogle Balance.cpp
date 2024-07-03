#include <bits/stdc++.h>
using namespace std;

int caseNo=0, N, curr;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    while(scanf("%d", &N), N){
        int suppose = 0, actual = 0;
        while (N--){
            scanf("%d", &curr);
            if(curr) suppose++;
            else actual++;
        }
        printf("Case %d: %d\n", ++caseNo, suppose - actual);
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}