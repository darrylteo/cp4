#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> t;
    while (t--) {
        int w, h, n, ships[2] = {}; // ships[0]: player1 ships, ships[1]: player2 ships
        cin >> w >> h >> n;
        char tmp[100], board[2][h][w]; // board[0]: player1 board, board[1]: player2 board
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < h; j++) {
                cin >> tmp;
                for (int k = 0; k < w; k++) {
                    board[i][j][k] = tmp[k];
                    if (tmp[k] == '#') {
                        ships[i]++;
                    }
                }
            }
        }

        int turn = 0, end = 0; // turn = 0: player1, turn = 1: player2... so we attack board[1] first
        while (n--) {
            int x, y;
            cin >> y >> x; // my row and column opposite?
            x = h - x - 1; // since we read from bottom to top
            if (end) continue;
            if (board[1 - turn][x][y] == '#') {
                board[1 - turn][x][y] = '_'; // any char is fine, just not '#'
                ships[1 - turn]--;
                // end your turn if enemy has no ships left
                if (ships[1 - turn] == 0) {
                    turn = 1 - turn; // enemy turn
                    // same number of turns, not same number of moves!!
                    // if (turn==0) means enemy played same number of turns as you already
                    if (turn == 0) end = 1;
                }
            } else {
                turn = 1 - turn; // enemy turn
            }
            // game end if both players have no ships left
            if (ships[1 - turn] == 0 && ships[turn] == 0) {
                end = 1;
            }
        }
        if (ships[0] == 0 && ships[1] > 0) {
            cout << "player two wins" << endl;
        } else if (ships[1] == 0 && ships[0] > 0) {
            cout << "player one wins" << endl;
        } else {
            cout << "draw" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

