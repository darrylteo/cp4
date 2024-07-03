#include <bits/stdc++.h>

using namespace std;

int N;
char test[100];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);
    while (N--) {
        scanf("%s", test);
        int score = 0;
        int cnt = 0;
        for (int i = 0; i < strlen(test); i++) {
            if (test[i] == 'O') {
                cnt++;
                score += cnt;
            } else {
                cnt = 0;
            }
        }
        printf("%d\n", score);
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}