#include <bits/stdc++.h>
using namespace std;

int caseNo = 0, n, currNo;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d", &n) != EOF){
        int mmin = INT_MAX, mmax = INT_MIN, mrange;
        while (n--){
            scanf("%d", &currNo);
            if (currNo < mmin){
                mmin = currNo;
            }
            if (currNo > mmax){
                mmax = currNo;
            }
        }
        mrange = mmax - mmin;
        printf("Case %d: %d %d %d\n", ++caseNo, mmin, mmax, mrange);
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}