#include <bits/stdc++.h>

using namespace std;

int finalMoveCount;

// note the way to feed a 2d array to a function
// idk why it works ._.
// a better practice might be to
// 1. initialize my 2d arrays globally and modify them
// 2. use another function to draw on robotMap/visited
// 3. use for loop instead of manually writing out NESW (only 4 so not too bad)
// 4. use recursion (but im newbie so maybe next time)
void mapToRobotMap(char originalMap[11][11], char robotMap[][11], int xStart, int yStart, int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; j++) {
            robotMap[i][j] = '?';
        }
    }
    robotMap[xStart - 1][yStart - 1] = originalMap[xStart - 1][yStart - 1];
    int xCurrent = xStart - 1, yCurrent = yStart - 1, moveCount = 0;
    int xNext = xCurrent, yNext = yCurrent, cont = 1, visited[11][11] = {};
    // mark the start point
    visited[xCurrent][yCurrent] = 1;

    // we can move to next square if it is not a wall and not visited
    while (cont) {

        // update robotMap NESW ... could have done loop...
        // North
        xNext = xCurrent - 1;
        if (xNext >= 0) {
            robotMap[xNext][yNext] = originalMap[xNext][yNext];
        }
        xNext = xCurrent;
        // East
        yNext = yCurrent + 1;
        if (yNext < M) {
            robotMap[xNext][yNext] = originalMap[xNext][yNext];
        }
        yNext = yCurrent;
        // South
        xNext = xCurrent + 1;
        if (xNext < N) {
            robotMap[xNext][yNext] = originalMap[xNext][yNext];
        }
        xNext = xCurrent;
        // West
        yNext = yCurrent - 1;
        if (yNext >= 0) {
            robotMap[xNext][yNext] = originalMap[xNext][yNext];
        }
        yNext = yCurrent;

        // move to next square
        while (true) {
            // North
            xNext = xCurrent - 1;
            if (originalMap[xNext][yNext] != 'X' && visited[xNext][yNext] == 0 && xNext >= 0) {
                break;
            }
            xNext = xCurrent; // go back if no way
            // East
            yNext = yCurrent + 1;
            if (originalMap[xNext][yNext] != 'X' && visited[xNext][yNext] == 0 && yNext < M) {
                break;
            }
            yNext = yCurrent; // go back if no way
            // South
            xNext = xCurrent + 1;
            if (originalMap[xNext][yNext] != 'X' && visited[xNext][yNext] == 0 && xNext < N) {
                break;
            }
            xNext = xCurrent; // go back if no way
            // West
            yNext = yCurrent - 1;
            if (originalMap[xNext][yNext] != 'X' && visited[xNext][yNext] == 0 && yNext >= 0) {
                break;
            }
            yNext = yCurrent; // go back if no way
            cont = 0;
            break;
        }

        if (cont) {
            // mark the move visited
            visited[xCurrent][yCurrent] = 1;

            // continue loop
            xCurrent = xNext;
            yCurrent = yNext;
            moveCount++;
        }
    }
    // mark the number of moves on robotMap
    finalMoveCount = moveCount;
}

void printRobotMap(char robotMap[][11], int N, int M) {
    cout << endl;
    for (int i = 0; i < M; ++i) {
        cout << "|---";
    }
    cout << "|" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "|";
        for (int j = 0; j < M; j++) {
            cout << " " << robotMap[i][j] << " |";
        }
        cout << endl;
        for (int j = 0; j < M; ++j) {
            cout << "|---";
        }
        cout << "|" << endl;
    }
    cout << endl;
    cout << "NUMBER OF MOVEMENTS: " << finalMoveCount << endl;

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N, M, xStart, yStart;
    while (cin >> N >> M, N) {
        cin >> xStart >> yStart;
        char originalMap[11][11] = {}, robotMap[11][11] = {};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; j++) {
                char c;
                cin >> c;
                originalMap[i][j] = c;
            }
        }
        mapToRobotMap(originalMap, robotMap, xStart, yStart, N, M);
        printRobotMap(robotMap, N, M);

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}