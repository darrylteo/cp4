#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> N;
    while (N--){
        int countX = 0, countO = 0;
        char board[3][3];
        string s;
        for (int i = 0; i < 3; i++){
            cin >> s;
            for (int j = 0; j < 3; j++){
                board[i][j] = s[j];
                if (board[i][j] == 'X') countX++;
                else if (board[i][j] == 'O') countO++;
            }
        }
        bool Xwin = false, Owin = false;
        // check rows and cols
        for (int i = 0; i < 3; i++){
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                if (board[i][0] == 'X') Xwin = true;
                else if (board[i][0] == 'O') Owin = true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if (board[0][i] == 'X') Xwin = true;
                else if (board[0][i] == 'O') Owin = true;
            }
        }
        // check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if (board[0][0] == 'X') Xwin = true;
            else if (board[0][0] == 'O') Owin = true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if (board[0][2] == 'X') Xwin = true;
            else if (board[0][2] == 'O') Owin = true;
        }

        // if X wins, X should have one more move than O
        // if O wins, X and O should have the same number of moves
        if (Xwin && countX != countO + 1) cout << "no" << endl;
        else if (Owin && countX != countO) cout << "no" << endl;
        else if (Xwin && Owin) cout << "no" << endl;
        else if (countX != countO + 1 && countX != countO) cout << "no" << endl;
        else cout << "yes" << endl;


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

