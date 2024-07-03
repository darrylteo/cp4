#include <bits/stdc++.h>

using namespace std;

int m, qnList[26];
char qn, outcome[6];


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %c %s", &m, &qn, &outcome);
    int score = 0, right = 0;
    while(m != -1){
        if (strcmp(outcome, "right") == 0){
            right += 1;
            score += m;
            score += qnList[qn - 'A' + 1];
        }
        else{
            qnList[qn - 'A' + 1] += 20;
        }
        scanf("%d %c %s", &m, &qn, &outcome);
    }
    printf("%d %d\n", right, score);



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}