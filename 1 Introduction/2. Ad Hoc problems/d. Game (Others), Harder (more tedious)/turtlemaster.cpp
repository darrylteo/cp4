#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    map<char, map<char, char>> face;
    face['r']['R'] = 'd'; // facing right, told to turn right, end up face down
    face['r']['L'] = 'u'; // facing right, told to turn left, end up face up
    face['u']['R'] = 'r'; // facing up, told to turn right, end up face right
    face['u']['L'] = 'l'; // facing up, told to turn left, end up face left
    face['l']['R'] = 'u'; // facing left, told to turn right, end up face up
    face['l']['L'] = 'd'; // facing left, told to turn left, end up face down
    face['d']['R'] = 'l'; // facing down, told to turn right, end up face left
    face['d']['L'] = 'r'; // facing down, told to turn left, end up face right


    char board[8][8], currDir = 'r';
    int currX = 0, currY = 7;
    string tmp;
    for (int i = 0; i < 8; i++) {
        cin >> tmp;
        for (int j = 0; j < 8; j++) {
            board[i][j] = tmp[j];
        }
    }
    cin >> tmp;
    // const so that I don't accidentally change it
    // reference so that I don't copy it
    for (char const &i : tmp) {
        // 2 turtle errors, 1. out of board, 2. hit a C or I
        if (i == 'F') {
            if (currDir == 'r') {
                if (currX + 1 < 8) {
                    currX++;
                } else {
                    cout << "Bug!" << endl;
                    return 0;
                }
            } else if (currDir == 'l') {
                if (currX - 1 >= 0) {
                    currX--;
                } else {
                    cout << "Bug!" << endl;
                    return 0;
                }
            } else if (currDir == 'u') {
                if (currY - 1 >= 0) {
                    currY--;
                } else {
                    cout << "Bug!" << endl;
                    return 0;
                }
            } else if (currDir == 'd') {
                if (currY + 1 < 8) {
                    currY++;
                } else {
                    cout << "Bug!" << endl;
                    return 0;
                }
            }
            if (board[currY][currX] == 'C' || board[currY][currX] == 'I') {
                cout << "Bug!" << endl;
                return 0;
            }
        } else if (i == 'R') {
            currDir = face[currDir]['R'];
        } else if (i == 'L') {
            currDir = face[currDir]['L'];
        } else if (i == 'X') {
            // for X, only OK if there is a I 1 step away
            if (currDir == 'r' && currX + 1 < 8 && board[currY][currX + 1] == 'I'){
                board[currY][currX + 1] = '.';
            } else if (currDir == 'l' && currX - 1 >= 0 && board[currY][currX - 1] == 'I'){
                board[currY][currX - 1] = '.';
            } else if (currDir == 'u' && currY - 1 >= 0 && board[currY - 1][currX] == 'I'){
                board[currY - 1][currX] = '.';
            } else if (currDir == 'd' && currY + 1 < 8 && board[currY + 1][currX] == 'I'){
                board[currY + 1][currX] = '.';
            } else {
                cout << "Bug!" << endl;
                return 0;
            }
        }
    }
    // if got here, no bug
    if (board[currY][currX] == 'D') {
        cout << "Diamond!" << endl;
    } else {
        cout << "Bug!" << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

