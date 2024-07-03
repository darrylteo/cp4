#include <bits/stdc++.h>

using namespace std;

int T, N;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        int maxDiff = INT_MIN, currScore = INT_MIN, currMax = INT_MIN;
        scanf("%d", &currMax);
        N--;
        while (N--) {
            scanf("%d", &currScore);
            if (currMax - currScore > maxDiff) {
                maxDiff = currMax - currScore;
            }
            if (currScore > currMax) {
                currMax = currScore;
            }
        }
        printf("%d\n", maxDiff);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}