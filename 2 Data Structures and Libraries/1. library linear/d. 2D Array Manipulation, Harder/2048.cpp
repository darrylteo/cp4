#include <bits/stdc++.h>

using namespace std;

// thought it was easy but tried to optimize flush right and wasted time...
// should have just done with the extra pushes since it is a small problem
// on kattis can check how many ppl TLE

int grid[4][4];

void rotateCW() {
    int temp[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            temp[i][j] = grid[i][j];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            grid[i][j] = temp[3 - j][i];
}

void pushRight() {
    // flush right
    for (int cnt = 0; cnt < 3; cnt++){
        for(int i = 0; i < 4; i++) {
            for (int j = 2; j >= 0; j--){
                if (grid[i][j+1] == 0) swap(grid[i][j], grid[i][j + 1]);
            }
        }
    }

    // combine right
    for(int i = 0; i < 4; i++) {
        for (int j = 2; j >= 0; j--){ // stuff on right combine FIRST
            if (grid[i][j] == grid[i][j + 1]) {
                grid[i][j+1] *= 2; // put on previous tile so doesn't FEVER TIME combo
                grid[i][j] = 0;
            }
        }
    }

    // flush right
    for (int cnt = 0; cnt < 3; cnt++){
        for(int i = 0; i < 4; i++) {
            for (int j = 2; j >= 0; j--){
                if (grid[i][j+1] == 0) swap(grid[i][j], grid[i][j + 1]);
            }
        }
    }
}

void printGrid() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> grid[i][j];

    int dir;
    cin >> dir;

    int CW = (dir + 2) % 4;

    for (int i = 0; i < (4 - CW) % 4; i++) {
        rotateCW();
    }
    pushRight();
    for (int i = 0; i < CW; i++) {
        rotateCW();
    }

    printGrid();

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




