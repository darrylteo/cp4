#include <bits/stdc++.h>

using namespace std;

int T, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        int a, currMax = 0, currMaxDuplicate, currMaxCandidate = 0, total = 0;
        // get all details... 1. highest no vote, 2. resp candidate,
        // 3. if there is duplicate, 4. total no. of votes
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            total += a;
            if (a == currMax) {
                currMaxDuplicate = 1;
            } else if (a > currMax) {
                currMaxDuplicate = 0;
                currMax = a;
                currMaxCandidate = i;
            } else {}
        }

        if (currMaxDuplicate) {
            printf("no winner\n");
        } else {
            if (currMax > total / 2) {
                printf("majority winner %d\n", currMaxCandidate + 1);
            } else {
                printf("minority winner %d\n", currMaxCandidate + 1);
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}