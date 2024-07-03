#include <bits/stdc++.h>

using namespace std;

char FEN[1000];


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%s", FEN) != EOF) {
        int i = 0, j = 0;
        // add all pieces to board
        char board[8][8], attacked[8][8] = {};
        // fill board with '.'s
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = '.';
            }
        }
        for (int k = 0; k < strlen(FEN); k++) {
            if (FEN[k] == '/') { // go next row
                for (j; j < 8; j++) {
                    board[i][j] = '.';
                }
                i++;
                j = 0;
            } else if (FEN[k] >= '1' && FEN[k] <= '8') { // if is number, go past next num column
                int num = FEN[k] - '0';
                for (int l = 0; l < num; l++) {
                    board[i][j] = '.';
                    j++;
                }
            } else {
                board[i][j] = FEN[k];
                j++;
            }
        }

        // go thru each square and mark attacked squares
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char piece = board[i][j];
                if (piece != '.') {
                    attacked[i][j] = '.'; // occupied
                    switch (piece) {
                        // board ranges from 0 to 7
                        case 'p':
                            if (i + 1 <= 7 && j - 1 >= 0) attacked[i + 1][j - 1] = '.'; // down left
                            if (i + 1 <= 7 && j + 1 <= 7) attacked[i + 1][j + 1] = '.'; // down right
                            break;
                        case 'P':
                            if (i - 1 >= 0 && j - 1 >= 0) attacked[i - 1][j - 1] = '.'; // up left
                            if (i - 1 >= 0 && j + 1 <= 7) attacked[i - 1][j + 1] = '.'; // up right
                            break;
                        case 'n':
                        case 'N':
                            if (i - 2 >= 0 && j - 1 >= 0) attacked[i - 2][j - 1] = '.'; // up left
                            if (i - 2 >= 0 && j + 1 <= 7) attacked[i - 2][j + 1] = '.'; // up right
                            if (i - 1 >= 0 && j - 2 >= 0) attacked[i - 1][j - 2] = '.'; // left up
                            if (i - 1 >= 0 && j + 2 <= 7) attacked[i - 1][j + 2] = '.'; // right up
                            if (i + 1 <= 7 && j - 2 >= 0) attacked[i + 1][j - 2] = '.'; // left down
                            if (i + 1 <= 7 && j + 2 <= 7) attacked[i + 1][j + 2] = '.'; // right down
                            if (i + 2 <= 7 && j - 1 >= 0) attacked[i + 2][j - 1] = '.'; // down left
                            if (i + 2 <= 7 && j + 1 <= 7) attacked[i + 2][j + 1] = '.'; // down right
                            break;
                        case 'b':
                        case 'B':
                            for (int k = 1; k < 8; k++) {
                                if (i - k >= 0 && j - k >= 0) attacked[i - k][j - k] = '.'; // up left
                                if (board[i - k][j - k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i - k >= 0 && j + k <= 7) attacked[i - k][j + k] = '.'; // up right
                                if (board[i - k][j + k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i + k <= 7 && j - k >= 0) attacked[i + k][j - k] = '.'; // down left
                                if (board[i + k][j - k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i + k <= 7 && j + k <= 7) attacked[i + k][j + k] = '.'; // down right
                                if (board[i + k][j + k] != '.') break;
                            }
                            break;
                        case 'r':
                        case 'R':
                            for (int k = 1; k < 8; k++) {
                                if (i - k >= 0) attacked[i - k][j] = '.'; // up
                                if (board[i - k][j] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i + k <= 7) attacked[i + k][j] = '.'; // down
                                if (board[i + k][j] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (j - k >= 0) attacked[i][j - k] = '.'; // left
                                if (board[i][j - k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (j + k <= 7) attacked[i][j + k] = '.'; // right
                                if (board[i][j + k] != '.') break;
                            }
                            break;
                        case 'q':
                        case 'Q':
                            for (int k = 1; k < 8; k++) {
                                if (i - k >= 0) attacked[i - k][j] = '.'; // up
                                if (board[i - k][j] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i + k <= 7) attacked[i + k][j] = '.'; // down
                                if (board[i + k][j] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (j - k >= 0) attacked[i][j - k] = '.'; // left
                                if (board[i][j - k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (j + k <= 7) attacked[i][j + k] = '.'; // right
                                if (board[i][j + k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i - k >= 0 && j - k >= 0) attacked[i - k][j - k] = '.'; // up left
                                if (board[i - k][j - k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i - k >= 0 && j + k <= 7) attacked[i - k][j + k] = '.'; // up right
                                if (board[i - k][j + k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i + k <= 7 && j - k >= 0) attacked[i + k][j - k] = '.'; // down left
                                if (board[i + k][j - k] != '.') break;
                            }
                            for (int k = 1; k < 8; k++) {
                                if (i + k <= 7 && j + k <= 7) attacked[i + k][j + k] = '.'; // down right
                                if (board[i + k][j + k] != '.') break;
                            }
                            break;
                        case 'k':
                        case 'K':
                            if (i - 1 >= 0 && j - 1 >= 0) attacked[i - 1][j - 1] = '.'; // up left
                            if (i - 1 >= 0) attacked[i - 1][j] = '.'; // up
                            if (i - 1 >= 0 && j + 1 <= 7) attacked[i - 1][j + 1] = '.'; // up right
                            if (j - 1 >= 0) attacked[i][j - 1] = '.'; // left
                            if (j + 1 <= 7) attacked[i][j + 1] = '.'; // right
                            if (i + 1 <= 7 && j - 1 >= 0) attacked[i + 1][j - 1] = '.'; // down left
                            if (i + 1 <= 7) attacked[i + 1][j] = '.'; // down
                            if (i + 1 <= 7 && j + 1 <= 7) attacked[i + 1][j + 1] = '.'; // down right
                            break;
                    }
                }
            }
        }
        int count = 0;
        // count number of attacked squares
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (attacked[i][j] == '.') count++;
            }
        }
        printf("%d\n", 64 - count);
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
