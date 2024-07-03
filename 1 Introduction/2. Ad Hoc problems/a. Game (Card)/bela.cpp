#include <bits/stdc++.h>

using namespace std;

map<string, map<string, int>> value;
char dominantSuit;
int N, score;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %c", &N, &dominantSuit);


    for (int i = 0; i < N * 4; i++) {
        char card[3];
        scanf("%s", card);
        char suit = card[1];
        char rank = card[0];
        if (rank == 'A') {
            score += 11;
        } else if (rank == 'K') {
            score += 4;
        } else if (rank == 'Q') {
            score += 3;
        } else if (rank == 'J') {
            if (suit == dominantSuit) {
                score += 20;
            } else {
                score += 2;
            }
        } else if (rank == 'T') {
            score += 10;
        } else if (rank == '9') {
            if (suit == dominantSuit) {
                score += 14;
            }
        }
    }

    printf("%d", score);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


