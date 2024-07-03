#include <bits/stdc++.h>

using namespace std;

// feels more ad hoc than graph

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, start;
    while (cin >> r >> c >> start) {
        if (r == 0 && c == 0 && start == 0) break;

        int currR = 0, currC = start - 1;
        vector<vector<char>> grid(r, vector<char>(c));
        vector<vector<int>> visited(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < c; ++j) {
                grid[i][j] = s[j];
            }
        }

        int ans = 0;
        while (true) {
            if (currR < 0 || currR >= r || currC < 0 || currC >= c) {
                cout << ans << " step(s) to exit" << endl;
                break;
            }
            if (visited[currR][currC] != 0) {
                cout << visited[currR][currC] - 1 << " step(s) before a loop of " << ans - visited[currR][currC] + 1 << " step(s)" << endl;
                break;
            }
            visited[currR][currC] = ans + 1;
            if (grid[currR][currC] == 'N') {
                currR--;
            } else if (grid[currR][currC] == 'S') {
                currR++;
            } else if (grid[currR][currC] == 'E') {
                currC++;
            } else if (grid[currR][currC] == 'W') {
                currC--;
            }
            ans++;
        }
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



