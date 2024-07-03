#include <bits/stdc++.h>

using namespace std;

int L, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %d", &L, &x);
    int curr = 0, p, noReject = 0;
    char s[10];
    while (x--){
        scanf("%s %d", s, &p);
        if (s[0] == 'e') {
            if (curr + p > L) {
                noReject++;
            } else {
                curr += p;
            }
        } else {
            if (curr - p < 0) {
                curr = 0;
            } else {
                curr -= p;
            }
        }
    }
    printf("%d\n", noReject);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}