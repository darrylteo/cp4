#include <bits/stdc++.h>

using namespace std;

int A, C;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // no. of cuts needed is how many times it goes down. go up no need cut.
    while (scanf("%d %d", &A, &C), A) {
        int prev, curr, cuts = 0;
        prev = A;
        while (C--){
            scanf("%d", &curr);
            cuts += max(0, prev - curr);
            prev = curr;
        }
        printf("%d\n", cuts);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}