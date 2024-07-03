#include <bits/stdc++.h>

using namespace std;

bool checkValid(vector<vector<char>> &board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'R') {
                // check until reach X or end of board or another R
                // up
                int k = j - 1;
                while (k >= 0 && board[i][k] != 'X' && board[i][k] != 'R') {
                    k--;
                }
                if (k >= 0 && board[i][k] == 'R') {
                    return false;
                }
                // down
                k = j + 1;
                while (k < n && board[i][k] != 'X' && board[i][k] != 'R') {
                    k++;
                }
                if (k < n && board[i][k] == 'R') {
                    return false;
                }
                // left
                k = i - 1;
                while (k >= 0 && board[k][j] != 'X' && board[k][j] != 'R') {
                    k--;
                }
                if (k >= 0 && board[k][j] == 'R') {
                    return false;
                }
                // right
                k = i + 1;
                while (k < n && board[k][j] != 'X' && board[k][j] != 'R') {
                    k++;
                }
                if (k < n && board[k][j] == 'R') {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n, n) {
        // read data
        vector<vector<char>> originalBoard(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < n; j++) {
                originalBoard[i][j] = line[j];
            }
        }

        // store bad positions (walls)
        bitset<17> badBits;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (originalBoard[i][j] == 'X') {
                    badBits[i * n + j] = true;
                }
            }
        }

        bitset<17> positions; // store combinations
        unsigned long long posCnt = 0;
        int bestCnt = 0;
        do {
            if (positions == 73) {
                int a = 0;
            }
            // we skip this combination if it has a rook overlap wall (easy check)
            auto badPositions = positions & badBits;
            if (badPositions.any()) {
                // next combination
                positions = ++posCnt;
                continue;
            }

            vector<vector<char>> myBoard = originalBoard;
            for (int i = 0; i < n * n; i++) {
                if (positions[i]) {
                    int x = i / n;
                    int y = i % n;
                    if (myBoard[x][y] == '.') { // put rook if empty
                        myBoard[x][y] = 'R';
                    }
                }
            }

            if (checkValid(myBoard)) {
                int currCnt = positions.count();
                bestCnt = max(bestCnt, currCnt);
            }

            // next combination
            positions = ++posCnt;
        } while (positions[n * n] == 0); // while not end of board

        cout << bestCnt << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}