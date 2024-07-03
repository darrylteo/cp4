#include <bits/stdc++.h>

using namespace std;

int M, N;
//lame question when u realize knights move to diff colored squares
//
//        note: use ceil for cases with different no. of black and white squares
//to round up since we put knights on the color with more squares available
//
//for elif cases 2*c board, let's draw
//if c is odd u can have a 2x2 stacks and 2x1 stack at end (+1)
//1 2 3 4 5 6 7 8 9      1 2 3 4 5 6 7 8 9
//|*|*| | |*|*| | |*| or |*|*| | |*|*| | |*|
//|*|*| | |*|*| | |*|    |*|*| | |*|*| | |*|
//
//if c is even u can have a 2x2 stacks (+2)
//example is 10 cols, mean can stack extra 2 knights
//1 2 3 4 5 6 7 8 9 0
//|*|*| | |*|*| | |*|*|
//|*|*| | |*|*| | |*|*|
//
//if c divisible by 4 u cannot stack knights efficiently
//1 2 3 4 5 6 7 8 9 0 1 2      1 2 3 4 5 6 7 8 9 0 1 2
//|*|*| | |*|*| | | | |*|*| or |*| |*| |*| |*| |*| |*| |
//|*|*| | |*|*| | | | |*|*|    | |*| |*| |*| |*| |*| |*|

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d %d", &N, &M), N || M) {
        if (N == 0 || M == 0) {
            printf("0 knights may be placed on a %d row %d column board.\n", N, M);
        }
        else if (N == 1 || M == 1) {
            printf("%d knights may be placed on a %d row %d column board.\n", max(N, M), N, M);
        } else if (N == 2 || M == 2) {
            int ans = (max(N, M) / 4) * 4;
            if (max(N, M) % 4 == 1) ans += 2;
            else if (max(N, M) % 4 > 1) ans += 4;
            printf("%d knights may be placed on a %d row %d column board.\n", ans, N, M);
        } else {
            printf("%d knights may be placed on a %d row %d column board.\n", (int) ceil((N * M) / 2.0), N, M);
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


