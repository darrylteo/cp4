#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    cout << T << '\n';
    while (T--) {
        int dirr = 0, dirc = 1; // initial direction is right
        int r = 1, c = 0; // initial position
        vector<string> maze = {"###",".##","###"};
        string query;
        cin >> query;
        for (char s: query) {
            int tmpDirr = dirr, tmpDirc = dirc;
            if (s == 'R') {
                dirr = tmpDirc;
                dirc = -tmpDirr;
            } else if (s == 'L') {
                dirr = -tmpDirc;
                dirc = tmpDirr;
            } else if (s == 'B'){
                dirr = -tmpDirr;
                dirc = -tmpDirc;
            }
            r += dirr;
            c += dirc;
            maze[r][c] = '.';
            if (r == 0) {
                maze.insert(maze.begin(), string(maze[0].size(), '#'));
                r++;
            } else if (r == maze.size() - 1) {
                maze.emplace_back(maze[0].size(), '#');
            } else if (c == maze[0].size() - 1) {
                for (string &row: maze) {
                    row.push_back('#');
                }
            }
        }
        cout << maze.size() << ' ' << maze[0].size() << '\n';
        for (string &row: maze) {
            cout << row << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

