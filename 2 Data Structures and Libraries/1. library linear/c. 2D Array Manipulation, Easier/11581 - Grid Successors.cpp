#include <bits/stdc++.h>

using namespace std;

// i have no clue what this question is asking for
// but i think it's asking for the minimum number of moves to get to the zero state
// (copilot is rude for guessing my intended comment)
// pretty sure the value of k is either zero or inf

vector<vector<int>> gridZero(3, vector<int>(3)), grid(3, vector<int>(3)), gridTest(3, vector<int>(3));

// update gridTest based on grid (previous state)
void f() {
    for(int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int up = 0, down = 0, left = 0, right = 0;
            if (i - 1 >= 0) up = grid[i - 1][j];
            if (i + 1 < 3) down = grid[i + 1][j];
            if (j - 1 >= 0) left = grid[i][j - 1];
            if (j + 1 < 3) right = grid[i][j + 1];
            gridTest[i][j] = (up + down + left + right) % 2;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 3; j++) {
                grid[i][j] = s[j] - '0';
                gridTest[i][j] = grid[i][j];
            }
        }

        int cnt = -1;
        if (gridTest == gridZero) {
            cout << cnt << endl;
            continue;
        }
        for (int i = 0; i < 5; i++) {
            f(); cnt++;
            grid = gridTest;

            if (gridTest == gridZero) {
                cout << cnt << endl;
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
