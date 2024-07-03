#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> grid;

// given top left corner, return -1 if have building, return cars squashed otherwise or 0 if no cars
int checkGrid2x2(int x, int y) {
    int count = 0;
    if (grid[x][y] == '#' || grid[x + 1][y] == '#' || grid[x][y + 1] == '#' || grid[x + 1][y + 1] == '#') {
        return -1;
    } else {
        if (grid[x][y] == 'X') {
            count++;
        }
        if (grid[x + 1][y] == 'X') {
            count++;
        }
        if (grid[x][y + 1] == 'X') {
            count++;
        }
        if (grid[x + 1][y + 1] == 'X') {
            count++;
        }
    }
    return count;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    grid.resize(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            grid[i][j] = s[j];
        }
    }
    vector<int> squashes;
    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C - 1; j++) {
            int temp = checkGrid2x2(i, j);
            if (temp == -1) {
                continue;
            } else {
                squashes.push_back(temp);
            }
        }
    }

    cout << std::count(squashes.begin(), squashes.end(), 0) << '\n';
    cout << std::count(squashes.begin(), squashes.end(), 1) << '\n';
    cout << std::count(squashes.begin(), squashes.end(), 2) << '\n';
    cout << std::count(squashes.begin(), squashes.end(), 3) << '\n';
    cout << std::count(squashes.begin(), squashes.end(), 4) << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}