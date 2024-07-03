#include <bits/stdc++.h>
using namespace std;

long long i = 0, n, currPos;
int mmin = INT_MAX, curr;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%lld", &n);
    while (n--){
        scanf("%d", &curr);
        if (curr < mmin) {
            mmin = curr;
            currPos = i;
        }
        i++;
    }
    printf("%lld", currPos);

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}