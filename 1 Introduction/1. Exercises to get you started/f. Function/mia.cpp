#include <bits/stdc++.h>
using namespace std;

int s0, s1, r0, r1, score1, score2;

int convertScore(int i0, int i1){
    int score = i0*10 + i1;
    if (score == 12 || score == 21) return 1000;
    else if (score == 66) return 999;
    else if (score == 55) return 998;
    else if (score == 44) return 997;
    else if (score == 33) return 996;
    else if (score == 22) return 995;
    else if (score == 11) return 994;
    else if (i0 > i1) return i0*10 + i1;
    else return i1*10 + i0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    while(scanf("%d %d %d %d", &s0, &s1, &r0, &r1), s0){
        score1 = convertScore(s0, s1);
        score2 = convertScore(r0, r1);
        if (score1 > score2) printf("Player 1 wins.\n");
        else if (score1 < score2) printf("Player 2 wins.\n");
        else printf("Tie.\n");
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}