#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string line;
    vector<string> board;
    vector<tuple<int, int, int>> valPos; // value, row, col
    while (getline(std::cin, line)) {
        board.push_back(line);

        // empty line means end of board, compute answer, print results and clear data
        if (line == "") {
            // collect the positions of all "dots" on the board
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    if (board[i][j] != '.') {
                        int val = board[i][j];
                        // if caps, push beyond the range of lowercase letters
                        if (val >= 65 && val <= 90) {
                            val += 100;
                        }
                        valPos.emplace_back(val, i, j);
                    }
                }
            }

            // if no numbers, print board and clear data
            if (valPos.size() == 0) {
                for (int i = 0; i < board.size(); i++) {
                    cout << board[i] << endl;
                }
                cout << endl;
                board.clear();
                valPos.clear();
                continue;
            }

            // sort the positions by value... default is by first element of tuple
            sort(valPos.begin(), valPos.end());

            // draw lines from 1 "dot" to next
            for (int i = 0; i < valPos.size() - 1; i++) {
                int row1 = get<1>(valPos[i]);
                int row2 = get<1>(valPos[i + 1]);
                int col1 = get<2>(valPos[i]);
                int col2 = get<2>(valPos[i + 1]);

                // if the rows are the same, draw a horizontal line
                if (row1 == row2) {
                    int start = min(col1, col2);
                    int end = max(col1, col2);
                    for (int j = start + 1; j < end; j++) {
                        if (board[row1][j] == '|') {
                            board[row1][j] = '+';
                        } else if (board[row1][j] == '.') {
                            board[row1][j] = '-';
                        }
                    }
                }
                    // if the cols are the same, draw a vertical line
                else if (col1 == col2) {
                    int start = min(row1, row2);
                    int end = max(row1, row2);
                    for (int j = start + 1; j < end; j++) {
                        if (board[j][col1] == '-') {
                            board[j][col1] = '+';
                        } else if (board[j][col1] == '.') {
                            board[j][col1] = '|';
                        }
                    }
                }
            }

            // print the board
            for (int i = 0; i < board.size(); i++) {
                cout << board[i] << endl;
            }

            board.clear();
            valPos.clear();
        }
    }


    // uhhh do everything again for last board

    // collect the positions of all "dots" on the board
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != '.') {
                int val = board[i][j];
                // if caps, push beyond the range of lowercase letters
                if (val >= 65 && val <= 90) {
                    val += 100;
                }
                valPos.emplace_back(val, i, j);
            }
        }
    }

    // if no numbers, print board and clear data
    if (valPos.size() == 0) {
        for (int i = 0; i < board.size(); i++) {
            cout << board[i] << endl;
        }
        board.clear();
        valPos.clear();
        return 0;
    }

    // sort the positions by value... default is by first element of tuple
    sort(valPos.begin(), valPos.end());

    // draw lines from 1 "dot" to next
    for (int i = 0; i < valPos.size() - 1; i++) {
        int row1 = get<1>(valPos[i]);
        int row2 = get<1>(valPos[i + 1]);
        int col1 = get<2>(valPos[i]);
        int col2 = get<2>(valPos[i + 1]);

        // if the rows are the same, draw a horizontal line
        if (row1 == row2) {
            int start = min(col1, col2);
            int end = max(col1, col2);
            for (int j = start + 1; j < end; j++) {
                if (board[row1][j] == '|') {
                    board[row1][j] = '+';
                } else if (board[row1][j] == '.') {
                    board[row1][j] = '-';
                }
            }
        }

            // if the cols are the same, draw a vertical line
        else if (col1 == col2) {
            int start = min(row1, row2);
            int end = max(row1, row2);
            for (int j = start + 1; j < end; j++) {
                if (board[j][col1] == '-') {
                    board[j][col1] = '+';
                } else if (board[j][col1] == '.') {
                    board[j][col1] = '|';
                }
            }
        }
    }

    // print the board
    for (int i = 0; i < board.size() - 1; i++) {
        cout << board[i] << endl;
    }
    cout << board[board.size() - 1];

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

