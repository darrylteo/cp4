#include <bits/stdc++.h>

using namespace std;

map<string, map<string, int>> value;
char in[5];
int N;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %c", &N, in);
    if (N == 1) {
        printf("1\n");
        return 0;
    } else {
        int shuffles = 0;
        int cards[N];
        for (int i = 0; i < N; i++) {
            cards[i] = i;
        }
        do {
            shuffles++;
            // if in shuffle
            if (in[0] == 'i') {
                int temp[N];
                for (int i = 0; i < N; i++) {
                    temp[i] = cards[i];
                }
                for (int i = 0; i < N; i++) {
                    cards[i] = temp[i / 2 + ((i + 1) % 2) * (N / 2)];
                }
            } else {
                int temp[N];
                for (int i = 0; i < N; i++) {
                    temp[i] = cards[i];
                }
                for (int i = 0; i < N; i++) {
                    cards[i] = temp[i / 2 + (i % 2) * ((N+1) / 2)];
                }
            }

        } while (is_sorted(cards, cards + N) == false);

        printf("%d\n", shuffles);
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


